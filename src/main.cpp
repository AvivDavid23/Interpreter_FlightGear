
#include <iostream>
#include <strings.h>
#include "Interpreter/Tables/BindingTable.h"
#include "Interpreter/Tables/SymbolTable.h"
#include "Interpreter/Tables/PathsTable.h"
#include "Interpreter/Expressions/ExpressionsParser.h"
#include "list"
#include "Interpreter/LexerParser/Lexer.h"
#include "Interpreter/Commands/ConnectCommand.h"
#include "Interpreter/LexerParser/Parser.h"
#include "Interpreter/Commands/OpenServerCommand.h"

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