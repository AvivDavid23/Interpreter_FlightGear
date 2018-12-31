//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
#define SECONDYEARPROJECT_BIU_MYSERIALSERVER_H


#include "Server.h"
namespace server_side {
/**
 * A type of Server, which take care of clients one by one
 */
    class MySerialServer : public server_side::Server {

        /**
         * Opens the server and waits for clients
         * @param port
         */
        void open(int port, ClientHandler* clientHandler);

        /**
         * Close the server
         */
        void close();
    };
}

#endif //SECONDYEARPROJECT_BIU_MYSERIALSERVER_H
