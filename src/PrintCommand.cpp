

#include "PrintCommand.h"
#include "SymbolTable.h"


int PrintCommand::execute(const vector<string> &line) {

    // Checks if output is in symbol map. if so, prints his value. else, prints output
    !SymbolTable::atTable(output) ? cout << output : cout << SymbolTable::getValue((output));
    cout << "\n";
    return 1;
}

PrintCommand::PrintCommand(unsigned int &index) : index(index) {}
