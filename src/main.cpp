
#include <iostream>
#include <strings.h>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"
#include "list"
#include "Lexer.h"
#include "ConnectCommand.h"
#include "OpenServerCommand.h"

/**
 * Initialization of private static vars of the project:
 */
BindingTable *BindingTable::s_instance = 0; // singleton
SymbolTable *SymbolTable::s_instance = 0; // singleton
PathsTable *PathsTable::s_instance = 0; // singleton

int main() {
    DataReaderServer::openServer(5400, 10);
    return 0;
}