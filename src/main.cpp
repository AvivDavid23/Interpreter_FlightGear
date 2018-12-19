
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"
#include "list"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;
//  std::cout << ExpressionsParser::shuntingYardAlg("-5+(4*10) - 3");

int main() {
    std::cout << ExpressionsParser::shuntingYardAlg("4 *(4- (3- 6))");

        return 0;
}