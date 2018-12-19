
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "OpenServerCommand.h"
#include "Lexer.h"
#include "Parser.h"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;


int main() {
    Lexer lexer;
    vector<string> words = lexer.active("file.txt");
    Parser parser;
    parser.createFunction(words);
    parser.commandParse(words);
    return 0;
}