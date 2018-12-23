
#include "DefineVarCommand.h"


void DefineVarCommand::execute(const vector<string> &line) {
    ++index; // skip 'Var'
    string key = line[index];
    index += 2; // skip '='
    if (line[index] == " bind") {
        ++index;
        string val = line[index];
        if(val[0] == '/'){ // start of a path
            globalMutex.lock();
            // set value in the table
            BindingTable::instance()->setValue(key, val.substr(1, val.length() - 2));
            SymbolTable::instance()->setValue(key,
                                              PathsTable::instance()->getValue(val.substr(1, val.length() - 2)));
            globalMutex.unlock();
        } else {
            globalMutex.lock();
            BindingTable::instance()->setValue(key, val);
            SymbolTable::instance()->setValue(key,
                                              SymbolTable::instance()->getValue(val));
            BindingTable::instance()->setValue(val, key);
            globalMutex.unlock();
        }
    } else {
        string val = line[index];
        globalMutex.lock();
        // calculate  and update
        SymbolTable::instance()->setValue(key,
                ExpressionsParser::shuntingYardAlg(ExpressionsParser::varsExtrication(val)));
        globalMutex.unlock();
    }
    ++index;
}

DefineVarCommand::DefineVarCommand(unsigned int &i) : index(i) {}
