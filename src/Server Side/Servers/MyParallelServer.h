//
// Created by dvir on 1/13/19.
//

#ifndef SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
#define SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include "../Client/ClientHandler.h"
#include <string.h>
#include <sys/socket.h>
#include "Server.h"
#include <thread>
#define TIMEOUT_SECONDE 1
namespace server_side {
    class MyParallelServer : public server_side::Server {
        int sockfd;
        bool active;
        std::vector<std::thread> threadList;
        bool first = true;
    public:

        MyParallelServer() = default;

/**
 * Open
 * @param port
 * @param clientHendler
 * the function opens socket for new client hendler
 */
        virtual void Open(int port, ClientHandler *clientHendler) {
            int sockfd, newsockfd, clilen;
            struct sockaddr_in serv_addr, cli_addr;
            int n;

            /* First call to socket() function */
            this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

            if (sockfd < 0) {
                throw std::runtime_error(std::string("ERROR opening socket"));
            }

            /* Initialize socket structure */
            bzero((char *) &serv_addr, sizeof(serv_addr));

            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(port);

            /* Now bind the host address using bind() call.*/
            if (bind(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                throw std::runtime_error(std::string("ERROR on binding"));
            }
            this->active = true;

        }

/**
 * start- open a thread to server client stream
 */
        void Start(int port,ClientHandler* clientHandler) {
            //open a thread to server-client stream
            std::thread t1(&MyParallelServer::MakeConnection, this, port,clientHandler);
            t1.join();
        }

/**
 * MakeConnection- create connection with client
 */
        void MakeConnection(int port,ClientHandler* clientHandler) {
            listen(this->sockfd, SOMAXCONN);

            int newsockfd, clilen, n;
            struct sockaddr_in cli_addr;
            clilen = sizeof(cli_addr);
            struct timeval tv;
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(this->sockfd, &rfds);
            //set a timeout timer
            tv.tv_sec = TIMEOUT_SECONDE;
            tv.tv_usec = TIMEOUT_SECONDE;
            while (this->active && (select(this->sockfd + 1, &rfds, nullptr, nullptr, &tv) || this->first)) {
                this->first = false;
                FD_ZERO(&rfds);
                FD_SET(this->sockfd, &rfds);
                /* Accept actual connection from the client */
                newsockfd = accept(this->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                if (newsockfd < 0) {
                    throw std::runtime_error(std::string("ERROR on accept"));
                }
                std::thread t1(&MyParallelServer::StartCliendHandlerThread, this, newsockfd ,clientHandler);
                threadList.push_back(std::move(t1));
            }
            for (unsigned long i = 0; i < this->threadList.size(); ++i) {
               threadList.at(i).join();
            }
        }

        void StartCliendHandlerThread(int port,ClientHandler* clientHandler) {
            clientHandler->handleClient(port);
        }

/**
 * Stop th server
 */
        virtual void Stop() {
            this->active = false;
            close(this->sockfd);
        }
    };
}
#endif //SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H