

#include "PrintCommand.h"


void PrintCommand::execute(const vector<string> &line) {

    // Checks if output is in symbol map. if so, prints his value. else, prints output
    globalMutex.lock();
    !SymbolTable::instance()->atTable(output) ? cout << output.substr(1, output.length() - 2) :
    cout << SymbolTable::instance()->getValue((output));
    globalMutex.unlock();
    cout << "\n";
}

PrintCommand::PrintCommand(unsigned int &index) : index(index) {}
