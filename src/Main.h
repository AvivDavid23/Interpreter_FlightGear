//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_MAIN_H
#define SECONDYEARPROJECT_BIU_MAIN_H

#include "MySerialServer.h"
#include "Solver.h"
#include "MyTestClientHandler.h"
#include "istream"
namespace boot{
    class Main {
    public:
        static int main(int argc, char **argv){
            ClientHandler *clientHandler = new MyTestClientHandler();
            clientHandler->handleClient(cin,cout);
        }
    };
}

#endif //SECONDYEARPROJECT_BIU_MAIN_H
