#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "ExpressionsParser.h"


OpenServerCommand::OpenServerCommand(unsigned int &index) : index(index){}

void OpenServerCommand::execute(const vector<string> &words) {
    int port, hz;
    try {
        port = (int) ExpressionsParser::shuntingYardAlg(words[index + 1]);
        hz = (int) ExpressionsParser::shuntingYardAlg((words[index + 2]));
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        exit(1);
    }
    thread t(&DataReaderServer::openServer, port, hz);
    t.detach();
}