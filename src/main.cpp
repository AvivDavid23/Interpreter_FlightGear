
#include <iostream>
#include <strings.h>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "ExpressionsParser.h"
#include "list"
#include "Lexer.h"
#include "ConnectCommand.h"
#include "Parser.h"
#include "OpenServerCommand.h"

/**
 * Initialization of private static vars of the project:
 * (these singletons dont have a cpp file so i do it here)
 */
BindingTable *BindingTable::s_instance = 0; // singleton
SymbolTable *SymbolTable::s_instance = 0; // singleton
PathsTable *PathsTable::s_instance = 0; // singleton
/**
 * @param argc 2 in our case
 * @param argv[1] have the name of the file.
 * @return
 */
int main(int argc, char **argv) {
    Lexer lexer;
    vector<string> words = lexer.active(argv[1]);
    Parser parser;
//     create table
    parser.createFunction(words);
    parser.commandParse(words);
//     close sockets
    close(DataReaderServer::getSocketFD());
    close(DataWriterClient::getSocketFD());
    return 0;
}