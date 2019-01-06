//
// Created by aviv on 12/20/18.
//

#include "AssignCommand.h"
/**
 * @param index in our line
 */
AssignCommand::AssignCommand(unsigned int &index) : index(index){}
/**
 * @param words the words
 */
void AssignCommand::execute(const vector<string> &words) {
    string key = words[index];
        index += 2; // skip key and '='
        // calculate the words[index]
    double val = ExpressionsParser::shuntingYardAlg(ExpressionsParser::varsExtrication(words[index]));
    globalMutex.lock();
    // set the value in our table
    SymbolTable::instance()->setValue(key,val);
    if (BindingTable::instance()->getValue(key)[0] == '/'){
        const string msg = "set " + BindingTable::instance()->getValue(key) +
                           " " + to_string(val) + "\r\n";
        globalMutex.unlock();
        // write the message
        DataWriterClient::writeMessage(msg);
    } else {
        SymbolTable::instance()->setValue(BindingTable::instance()->getValue(key), val);
        globalMutex.unlock();
    }
    ++index;
}