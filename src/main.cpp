
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;


int main() {
    std::cout << ExpressionsParser::shuntingYardAlg("-4 + 5");
    std::cout << "Hello Shin!\n";
    return 0;
}