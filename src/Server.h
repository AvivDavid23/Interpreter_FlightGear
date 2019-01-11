//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SERVER_H
#define SECONDYEARPROJECT_BIU_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    // Server Interface
    template <class Problem,class  Solution>
    class Server {
    public:
        /**
         * Opens the server and waits for clients
         * @param port
         * @param clientHandler
         */
        virtual void open(int port, ClientHandler* clientHandler) = 0;
        virtual void start(int port,ClientHandler* clientHandler) = 0;
        /**
         * Close the server
         */
        virtual void stopPro() = 0 ;
    };

}
#endif //SECONDYEARPROJECT_BIU_SERVER_H
