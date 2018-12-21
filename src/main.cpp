
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

int main() {
//    std::cout << ExpressionsParser::shuntingYardAlg("3-(-4)");
    Lexer lexer;
    vector<string> words = lexer.active("file.txt");
    return 0;
}