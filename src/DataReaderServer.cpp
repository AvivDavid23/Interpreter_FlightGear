
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
#include "DataReaderServer.h"

std::vector<std::string> DataReaderServer::splitByComma(char *buffer) {
    std::vector<std::string> vec;
    std::string tmp;
    while (*buffer) {
        while (*buffer != ',' && *buffer != '\n') {
            tmp += *buffer;
            ++buffer;
        }
        vec.push_back(tmp);
        tmp = "";
        ++buffer;
    }
    return vec;
}

void DataReaderServer::updatePathsTable(std::vector<std::string> vector) {
    for (int i = 0; i < PARAMETERS_SIZE; ++i) {
        PathsTable::instance()->setValue(pathsVec[i],atof(vector[i].c_str()));
    }
}

void DataReaderServer::updateSymbolTable() {
    for (auto iter = SymbolTable::instance()->getFirst() ; iter != SymbolTable::instance()->getEnd(); ++iter){
        SymbolTable::instance()->setValue(iter->first,PathsTable::instance()->getValue(BindingTable::instance()->
        getValue(iter->first)));
    }
}
void DataReaderServer::openServer(int port, int hz) {
    int sockfd, newsockfd, clilen;
    char buffer[500];
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
    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, 500);
        n = read(newsockfd, buffer, 500);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        updatePathsTable(splitByComma(buffer));
        updateSymbolTable();
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}