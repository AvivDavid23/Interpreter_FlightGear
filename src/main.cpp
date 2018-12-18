
#include <fstream>
#include "Parser.h"
#include "Lexer.h"
#include "DataReaderServer.h"
#define TEXT "file.txt"
int main() {
    DataReaderServer::openServer(5400, 10);
    return 0;
}