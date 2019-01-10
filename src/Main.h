//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_MAIN_H
#define SECONDYEARPROJECT_BIU_MAIN_H

#include "MySerialServer.h"
#include "Solver.h"
#include "MyTestClientHandler.h"
#include "istream"
#include "Server.h"
namespace boot{
    class Main {
    public:
        static int main(int argc, char **argv){
            server_side::Server<string,string> *server;
            ClientHandler *clientHandler = new MyTestClientHandler();
            server =  new server_side::MySerialServer<string,string>();
            server->open(atoi(argv[1]),clientHandler);
                clientHandler->handleClient(cin,cout);
        }
        };
}

#endif //SECONDYEARPROJECT_BIU_MAIN_H
