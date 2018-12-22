
//
// Created by dvir on 12/13/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <iostream>
#include "DataReaderServer.h"
#include "mutex"

void DataReaderServer::updatePathsTable(const char *buffer) {
    for (int i = 0; i < PARAMETERS_SIZE; ++i) {
        std::string tmp;
        while (*buffer != ',' && *buffer != '\n') {
            tmp += *buffer;
            ++buffer;
        }
        globalMutex.lock();
        PathsTable::instance()->setValue(pathsVec[i], atof(tmp.c_str()));
        globalMutex.unlock();
        tmp = "";
        if (*buffer != '\n') ++buffer;
    }
    ++buffer;
}

void DataReaderServer::updateSymbolTable() {
    for (auto iter = SymbolTable::instance()->getFirst(); iter != SymbolTable::instance()->getEnd(); ++iter) {
        // means the var is binned to a var
        globalMutex.lock();
        if (*BindingTable::instance()->getValue(iter->first).c_str() != '/') {
            SymbolTable::instance()->setValue(iter->first, SymbolTable::instance()->getValue(BindingTable::instance()->
                    getValue(iter->first)));
        } else {
            SymbolTable::instance()->setValue(iter->first, PathsTable::instance()->getValue(BindingTable::instance()->
                    getValue(iter->first)));
        }
        globalMutex.unlock();
    }
}

void DataReaderServer::openServer(int port, int hz) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    while (true) {
        bzero(buffer,BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        updatePathsTable(buffer);
        updateSymbolTable();
    }
}