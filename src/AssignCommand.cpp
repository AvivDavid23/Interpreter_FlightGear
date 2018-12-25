//
// Created by aviv on 12/20/18.
//

#include "AssignCommand.h"
AssignCommand::AssignCommand(unsigned int &index) : index(index){}

void AssignCommand::execute(const vector<string> &line) {
    string key = line[index];
    index += 2; // skip key and '='
    double val = ExpressionsParser::shuntingYardAlg(ExpressionsParser::varsExtrication(line[index]));
    globalMutex.lock();
    SymbolTable::instance()->setValue(key,val);
    if (BindingTable::instance()->getValue(key)[0] == '/'){
        const string msg = "set " + BindingTable::instance()->getValue(key) +
                           " " + to_string(SymbolTable::instance()->getValue(key)) + "\r\n";
        globalMutex.unlock();
        DataWriterClient::setMessage(msg);
    } else {
        SymbolTable::instance()->setValue(BindingTable::instance()->getValue(key), val);
        globalMutex.unlock();
    }
    ++index;
}