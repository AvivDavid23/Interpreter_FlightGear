
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"
#include "list"
#include "Lexer.h"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;
//  std::cout << ExpressionsParser::shuntingYardAlg("-5+(4*10) - 3");

int main() {
    Lexer lexer;
    vector<string> words = lexer.active("file.txt");
    return 0;
}