//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SERVER_H
#define SECONDYEARPROJECT_BIU_SERVER_H

#include "../Client/ClientHandler.h"

namespace server_side {
    // Server Interface
    class Server {
    public:
        /**
         * Opens the server and waits for clients
         * @param port
         * @param clientHandler
         */
        virtual void Open(int port, ClientHandler* clientHandler) = 0;
        virtual void Start(int port,ClientHandler* clientHandler) = 0;
        /**
         * Close the server
         */
        virtual void Stop() = 0;
    };

}
#endif //SECONDYEARPROJECT_BIU_SERVER_H
