//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_MAIN_H
#define SECONDYEARPROJECT_BIU_MAIN_H

#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "Server.h"

namespace boot {
    class Main {
    public:
        /**
         * @param argc how many inputs have from user.
         * @param argv inputs from the user.
         * @return
         */
        static int main(int argc, char **argv) {

            ClientHandler *clientHandler = new MyClientHandler();
            server_side::Server *server =  new server_side::MyParallelServer();
            server->open(atoi(argv[1]),clientHandler);
            return 0;
            }
    };
}

#endif //SECONDYEARPROJECT_BIU_MAIN_H
