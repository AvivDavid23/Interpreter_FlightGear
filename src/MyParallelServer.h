//
// Created by dvir on 1/13/19.
//

#ifndef SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
#define SECONDYEARPROJECT_BIU_MYPARALLELSERVER_H
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <sys/socket.h>
#include <thread>
namespace server_side {
    class MyParallelServer : public server_side::Server {
        int sockfd;
        bool active;
        vector<thread> threadList;
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
                throw runtime_error(string("ERROR opening socket"));
            }

            /* Initialize socket structure */
            bzero((char *) &serv_addr, sizeof(serv_addr));

            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(port);

            /* Now bind the host address using bind() call.*/
            if (bind(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                throw runtime_error(string("ERROR on binding"));
            }
            this->active = true;

        }

/**
 * start- open a thread to server client stream
 */
        void Start(int port,ClientHandler* clientHandler) {
            //open a thread to server-client stream
            thread t1(&MyParallelServer::MakeConnection, this, port,clientHandler);
            t1.join();
        }

/**
 * MakeConnection- create connection with client
 */
        void MakeConnection(int port,ClientHandler* clientHandler) {
            listen(this->sockfd, 5);

            int newsockfd, clilen, n;
            struct sockaddr_in cli_addr;
            clilen = sizeof(cli_addr);
            struct timeval tv;
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(this->sockfd, &rfds);
            //set a timeout timer
            tv.tv_sec = 40;
            tv.tv_usec = 0;
            while (this->active && (select(this->sockfd + 1, &rfds, nullptr, nullptr, &tv) || this->first)) {
                this->first = false;
                FD_ZERO(&rfds);
                FD_SET(this->sockfd, &rfds);
                /* Accept actual connection from the client */
                newsockfd = accept(this->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                if (newsockfd < 0) {
                    throw runtime_error(string("ERROR on accept"));
                }
                thread t1(&MyParallelServer::StartCliendHandlerThread, this, newsockfd ,clientHandler);
                this->threadList.push_back(std::move(t1));
            }
            for (int i = 0; i < this->threadList.size(); ++i) {
                this->threadList.at(i).join();
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
