//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
#define SECONDYEARPROJECT_BIU_MYSERIALSERVER_H

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
#define TIMEOUT_SECONDE 1
#define TIMEOUT_MILISECONDE 0
using namespace std;
namespace server_side {
/**
 * A type of Server, which take care of clients one by one
 */
    class MySerialServer : public server_side::Server {
        bool openCustumer = false;
        int portID;
        int sockfd;
    public:
        MySerialServer()
        {}
        /**
         * Opens the server and waits for clients
         * @param port
         */
        void Open(int port, ClientHandler* clientHandler) {
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
            listen(sockfd, 1);
            thread t(&MySerialServer::Start, this, port, clientHandler);
            t.join();
            //

        }
        void Start(int port,ClientHandler* clientHandler) {
            struct sockaddr_in cli_addr;
            int newsockfd,clilen;
            clilen = sizeof(cli_addr);
            fd_set rfds;
            struct timeval tv;
            FD_ZERO(&rfds);
            FD_SET(this->sockfd, &rfds);
            bool check = false;
//            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            //set a timeout timer
//            tv.tv_sec = TIMEOUT_SECONDE;
//            tv.tv_usec = TIMEOUT_MILISECONDE;
//            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv));
            openCustumer = true;
            /* Accept actual connection from the client */
            // the massage.
            while(true) {
                    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                string output, input;
                if (newsockfd < 0) {
                    if (errno == EWOULDBLOCK) {
                        cout << "timeout!" << endl;
                        break;
                    } else {
                        perror("other error");
                        exit(2);
                    }
                }
                clientHandler->handleClient(newsockfd);
               if(openCustumer) {
                   tv.tv_sec = 1;
                   tv.tv_usec = 0;
                   setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv));
                   openCustumer = false;
               }
            }
            }
        /**
         * Close the server
         */
         void Stop() {
            this->openCustumer = false;
            close(this->sockfd);
         }
    };
}


#endif //SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
