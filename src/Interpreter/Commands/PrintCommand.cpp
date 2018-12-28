

#include "PrintCommand.h"


void PrintCommand::execute(const vector<string> &line) {

    // Checks if output is in symbol map. if so, prints his value. else, prints output
    globalMutex.lock();
    index++;
    while(line[index][line[index].length() - 1] != '"' && !SymbolTable::instance()->atTable(line[index])){
        output += line[index];
        output += " ";
        ++index;
    }
    output += line[index];
    ++index;
    // instructions of what need to print.
    !SymbolTable::instance()->atTable(output) ? cout << output.substr(1, output.length() - 2) :
    cout << SymbolTable::instance()->getValue((output));
    output = "";
    globalMutex.unlock();
    cout << "\n";
}

PrintCommand::PrintCommand(unsigned int &index) : index(index) {}
