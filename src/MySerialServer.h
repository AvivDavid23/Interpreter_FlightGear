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

#include <string.h>
#include <sys/socket.h>
#include <thread>
#include "Server.h"
namespace server_side {
/**
 * A type of Server, which take care of clients one by one
 */
    class MySerialServer : public server_side::Server {
        bool openCustumer = false;
        int portID;
    public:
        /**
         * Opens the server and waits for clients
         * @param port
         */
        void open(int port, ClientHandler* clientHandler);
        void start(int port,ClientHandler* clientHandler);
        /**
         * Close the server
         */
        void stopPro();
//        void MakeConnection();
         bool isOpen(){ return openCustumer;}

    };
}

#endif //SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
