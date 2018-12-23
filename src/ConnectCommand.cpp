
#include "ConnectCommand.h"
#include "thread"
#include "DataReaderServer.h"
ConnectCommand::ConnectCommand(unsigned int &index) : index(index) {}

void ConnectCommand::execute(const vector<string> &line) {
    int port;
    std::string adr;
    try {
        adr = line[index + 1];
        port = (int) ExpressionsParser::shuntingYardAlg(line[index + 2]);
        index += 3;
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        exit(1);
    }
    while (!DataReaderServer::isOpen()){
        // wait until simulator is connected
    }
    thread t(&DataWriterClient::createClient, port, adr);
    t.detach();
}

