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
    thread t(&DataReaderServer::openServer,port,hz);
    t.detach();
    return 3;
}

vector<string> OpenServerCommand:: argv (const  vector<string> & words){
    int count =0;
    bool ans = false;
    int argv = 2; // number of parameter.
    if(is_number(words[index])) {
        count++;
    }
}

bool OpenServerCommand::is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}