
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"
#include "list"
#include "Lexer.h"
#include "DataReaderServer.h"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;

int main() {
   DataReaderServer::openServer(5400, 10);
    return 0;
}