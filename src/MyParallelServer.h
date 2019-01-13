//
// Created by dvir on 1/13/19.
//

#ifndef SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
#define SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H

#include "Server.h"
#define PARAMETERS_SIZE 23
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <sstream>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include "Server.h"
#define TIMEOUT_SECONDE 10
#define TIMEOUT_MILISECONDE 0
using namespace std;
/**
 * A type of Server, which take care of clients one by one
 */
 namespace server_side {
     template<class Problem, class Solution>
     class MyParallelServer : public server_side::Server<Problem, Solution> {
         bool openCustumer = false;
         int portID;
         int sockfd;
     public:
         MyParallelServer<Problem, Solution>() {};

         /**
          * Opens the server and waits for clients
          * @param port
          */
         void open(int port, ClientHandler *clientHandler) {
             int newsockfd, clilen;
             char buffer[BUFFER_SIZE];
             std::string values;
             std::string leftovers;
             bzero(buffer, BUFFER_SIZE);
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

             // only one can conncet.
             listen(sockfd, SOMAXCONN);
             thread t(&MyParallelServer::start, this, port, clientHandler);
             t.join();
             //

         }

         void start(int port, ClientHandler *clientHandler) {
             struct sockaddr_in cli_addr;
             int newsockfd, clilen;
             clilen = sizeof(cli_addr);
             fd_set rfds;
             struct timeval tv;
             FD_ZERO(&rfds);
             FD_SET(this->sockfd, &rfds);
             //set a timeout timer
             tv.tv_sec = TIMEOUT_SECONDE;
             tv.tv_usec = TIMEOUT_MILISECONDE;
             setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv));
             openCustumer = true;
             /* Accept actual connection from the client */
             // the massage.
             while (openCustumer) {
                 newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                 string output, input;
                 if (newsockfd < 0) {
                     if (errno == EWOULDBLOCK) {
                         cout << "timeout!" << endl;
                         stopPro();
                         break;
                     } else {
                         perror("other error");
                         stopPro();
                         break;
                     }
                 }
                 clientHandler->handleClient(newsockfd);
             }
         }

         /**
          * Close the server
          */
         void stopPro() {
             this->openCustumer = false;
             close(this->portID);
         }
     };
 }

#endif //SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
