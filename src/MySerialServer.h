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
#define TIMEOUT_SECONDE 10
#define TIMEOUT_MILISECONDE 0
using namespace std;
namespace server_side {
/**
 * A type of Server, which take care of clients one by one
 */
 template <class Problem,class Solution>
    class MySerialServer : server_side::Server<Problem,Solution> {
        bool openCustumer = false;
        int portID;
    public:
        MySerialServer<Problem,Solution>(int port)
                {this->portID = port;}
        /**
         * Opens the server and waits for clients
         * @param port
         */
        void open(int port, ClientHandler* clientHandler){
            int sockfd, newsockfd, clilen;
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

            /* Now start listening for the clients, here process will
               * go in sleep mode and will wait for the incoming connection
            */
            /* Now start listening for the clients, here process will
             * go in sleep mode and will wait for the incoming connection
          */

            // only one can conncet.
            listen(sockfd, 1);
            clilen = sizeof(cli_addr);
            fd_set rfds;
            struct timeval tv;
            FD_ZERO(&rfds);
            FD_SET(this->sockfd, &rfds);
            //set a timeout timer
            tv.tv_sec = TIMEOUT_SECONDE;
            tv.tv_usec = TIMEOUT_MILISECONDE;
            while (this->active && select(this->sockfd + 1, &rfds, nullptr, nullptr, &tv)) {
            /* Accept actual connection from the client */
            // the massage.
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
                if (newsockfd < 0)	{
                    if (errno == EWOULDBLOCK)	{
                      cout << "timeout!" << endl;
                        exit(2);
                    }	else	{
                        perror("other error");
                        exit(3);
                    }
                }
            openCustumer = true;
            string output,input;
            int start = leftovers.length() ? leftovers.length() - 1 : 0;
            // set input
            read(newsockfd, buffer + start, BUFFER_SIZE - start);
            input = string(buffer);
            // set output
//            output = write(this->portID,"1",1);
            istringstream realInput(input);
            stringstream output1(output);
//     clientHandler->handleClient(realInput,output1);
                }
        }
        void start(int port,ClientHandler* clientHandler) {
            portID = port;
            thread t(&MySerialServer::open, this, port, clientHandler);
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

#endif //SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
