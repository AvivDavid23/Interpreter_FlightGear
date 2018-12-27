#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "ExpressionsParser.h"


OpenServerCommand::OpenServerCommand(unsigned int &index) : index(index){}
/**
 *
 * @param words the words of the file.txt
 */
void OpenServerCommand::execute(const vector<string> &words) {
    int port, hz;
    try {
        port = (int) ExpressionsParser::shuntingYardAlg(words[index + 1]);
        hz = (int) ExpressionsParser::shuntingYardAlg((words[index + 2]));
        index += 3;
        // fail to open the server.
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        exit(1);
    }
    // new thread for the server(simulator).
    thread t(&DataReaderServer::openServer, port, hz);
    while (!DataReaderServer::isOpen()){
        // wait...
    }
    t.detach();
}