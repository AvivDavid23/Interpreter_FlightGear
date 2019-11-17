
#include "DefineVarCommand.h"


void DefineVarCommand::execute(const vector<string> &line) {
    ++index; // skip 'Var'
    string key = line[index];
    index += 2; // skip '='
    if (line[index] == " bind") {
        ++index;
        string val = line[index];
        if (val[1] == '/') { // start of a path
            globalMutex.lock();
            // set value in the table
            val = val.substr(1, val.length() - 2);
            if (PathsTable::instance()->atTable(val)){
                // if the path is in paths table
                BindingTable::instance()->setValue(key, val);
                SymbolTable::instance()->setValue(key,PathsTable::instance()->getValue(val));
            } else {
                BindingTable::instance()->setValue(key, val);
                SymbolTable::instance()->setValue(key,0);
            }
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
