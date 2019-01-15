//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_MAIN_H
#define SECONDYEARPROJECT_BIU_MAIN_H

#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "Solver.h"
#include "MyClientHandler.h"
#include "istream"
#include "Server.h"

namespace boot {
    class Main {
    public:
        static int main(int argc, char **argv) {
            server_side::Server<MatrixMaze, string> *server;
            ClientHandler *clientHandler = new MyClientHandler();
            server =  new server_side::MySerialServer<MatrixMaze,string>();
            server->open(atoi(argv[1]),clientHandler);
//            while (true) {
//                thread thread1(&server_side::MyParallelServer<MatrixMaze, string>::open, server, atoi(argv[1]), clientHandler);
//                break;
            }
    };
}

#endif //SECONDYEARPROJECT_BIU_MAIN_H
