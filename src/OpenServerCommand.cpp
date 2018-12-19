#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "ShuntingYard.h"


OpenServerCommand::OpenServerCommand(unsigned int &index) : index(index){}

int OpenServerCommand::execute(const vector<string> &words) {
    int port, hz;
    try {
        port = (int) ShuntingYard::shuntingYardAlg(words[index + 1]);
        hz = (int) ShuntingYard::shuntingYardAlg((words[index + 2]));
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        return 0;
    }
    thread t(&DataReaderServer::openServer, port, hz);
    t.detach();
    return 3;
}