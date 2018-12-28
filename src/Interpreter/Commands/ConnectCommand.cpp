
#include "ConnectCommand.h"
#include "thread"
#include "../ServerClient/DataReaderServer.h"
ConnectCommand::ConnectCommand(unsigned int &index) : index(index) {}
/**
 * @param words in the file.
 */
void ConnectCommand::execute(const vector<string> &words) {
    int port;
    std::string adr;
    try {
        adr = words[index + 1];
        port = (int) ExpressionsParser::shuntingYardAlg(words[index + 2]);
        index += 3;
    } catch (...) {
        cerr << "Syntax/Parameter Error!" << endl;
        exit(1);
    }
    DataWriterClient::createClient(port, adr);
}

