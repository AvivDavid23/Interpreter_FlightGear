
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

bool DataReaderServer::open = false;

unsigned int DataReaderServer::numberOfNewLine(const char *buffer) {
    const char *pt = buffer;
    unsigned int x = 0;
    while (*pt) {
        if (*pt == '\n')++x;
        ++pt;
    }
    return x;
}

std::vector<std::string> DataReaderServer::splitByComma(const char *buffer) {
    std::vector<std::string> vec;
    std::string tmp;
    while (*buffer != '\n') {
        while (*buffer != ',' && *buffer != '\n') {
            tmp += *buffer;
            ++buffer;
        }
        vec.emplace_back(tmp);
        tmp = "";
        if (*buffer != '\n') ++buffer;
    }
    return vec;
}

void DataReaderServer::updatePathsTable(std::vector<std::string> vec) {
    globalMutex.lock();
    for (int i = 0; i < PARAMETERS_SIZE; ++i) {
        PathsTable::instance()->setValue(pathsVec[i], atof(vec[i].c_str()));
    }
    globalMutex.unlock();
}

void DataReaderServer::updateSymbolTable() {
    globalMutex.lock();
    for (auto iter = SymbolTable::instance()->getFirst(); iter != SymbolTable::instance()->getEnd(); ++iter) {
        // means the var is binned to a var
        globalMutex.lock();
        if (*BindingTable::instance()->getValue(iter->first).c_str() != '/') {
            SymbolTable::instance()->setValue(iter->first, SymbolTable::instance()->getValue(BindingTable::instance()->
                    getValue(iter->first)));
        } else {
            if (PathsTable::instance()->atTable(BindingTable::instance()->
                    getValue(iter->first))) {
                SymbolTable::instance()->setValue(iter->first,
                                                  PathsTable::instance()->getValue(BindingTable::instance()->
                                                          getValue(iter->first)));
            }
        }
    }
    globalMutex.unlock();
}

void DataReaderServer::openServer(int port, int hz) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    while (sockfd < 0) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
       //try...
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
    open = true;
    char buffer[BUFFER_SIZE];
    std::string values;
    std::string leftovers;
    bzero(buffer, BUFFER_SIZE);
    while (true) {
        // to know where to put data:
        n = read(newsockfd, buffer, BUFFER_SIZE);
        char* pt = buffer;
        if (numberOfNewLine(pt)  >= 2){
            while (*pt != '\n') ++pt;
            ++pt;
        }
        updatePathsTable(splitByComma(pt));
        updateSymbolTable();
        bzero(buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}