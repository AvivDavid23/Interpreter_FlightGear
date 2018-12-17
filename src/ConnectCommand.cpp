
#include <string>
#include "ConnectCommand.h"
#include "Shunting-Yard.h"
#include "thread"
#include "DataWriterClient.h"
ConnectCommand::ConnectCommand( map<string, double> &symbolTable,unsigned int &index) : symbolTable(symbolTable),
index(index) {}

int ConnectCommand::execute(const vector<string> &words, unsigned int i) {
    int port;
    string address;
    try {
        port = (int) ShuntingYard::shuntingYardAlg(words[index + 1]);
        address = words[index + 2];
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        return 0;
    }
    thread t(&DataWriterClient::createClient, port, address, std::ref(symbolTable));
    t.detach();
    return 3;
}
