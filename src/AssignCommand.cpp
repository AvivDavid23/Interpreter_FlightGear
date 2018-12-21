//
// Created by aviv on 12/20/18.
//

#include "AssignCommand.h"
AssignCommand::AssignCommand(unsigned int &index) : index(index){}

void AssignCommand::execute(const vector<string> &line) {
    string key = line[index];
    index += 2; // skip key and '='
    globalMutex.lock();
    SymbolTable::instance()->setValue(key,
            ExpressionsParser::shuntingYardAlg(ExpressionsParser::varsExtrication(line[index])));
    const string msg = "set " + BindingTable::instance()->getValue(key) +
            " " + to_string(SymbolTable::instance()->getValue(key)) + "\r\n";
    globalMutex.unlock();
    DataWriterClient::setMessage(msg);
    ++index;
}