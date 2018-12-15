
#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "Shunting-Yard.h"


OpenServerCommand::OpenServerCommand(map<string, double> &symbolTable, unsigned int &index) : symbolTable(symbolTable),
                                                                                              index(index){}

int OpenServerCommand::execute(const vector<string> &words, unsigned int index) {
    int port, hz;
    try {
        port = (int) shuntingYardAlg(words[index + 1]);
        hz = (int) shuntingYardAlg(words[index + 2]);
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        return 0;
    }
    thread t(&DataReaderServer::openServer, port, hz, std::ref(symbolTable));
    t.detach();
    return 3;
}

