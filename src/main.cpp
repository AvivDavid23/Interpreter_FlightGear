
#include <fstream>
#include "Parser.h"
#include "Lexer.h"
#define TEXT "file.txt"
int main() {
    Lexer lexer;
    vector<string>words = lexer.active(TEXT);
    Parser parser;
    parser.createFunction(words);
    parser.commandParse(words);

    return 0;
}