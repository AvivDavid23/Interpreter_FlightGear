
#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "Shunting-Yard.h"
#include "DataReaderServer.h"

// TODO: thread, client-server.
OpenServerCommand::OpenServerCommand(unsigned int &index) : index(index) {}

int OpenServerCommand::execute(const vector<string> &words, unsigned int index) {
    int port, hz;
    try {
        port = (int) shuntingYardAlg(words[index + 1]);
        hz = (int) shuntingYardAlg(words[index + 2]);
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        return 0;
    }
    DataReaderServer server(port, hz);
    server.openServer();
    return 3;
}

