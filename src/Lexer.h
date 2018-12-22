//
// Created by dvir on 12/17/18.
//

#ifndef SECONDYEARPROJECT_BIU_LEXER_H
#define SECONDYEARPROJECT_BIU_LEXER_H
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "SymbolTable.h"
using namespace std;
class Lexer {
public:
    vector<string> active(const string &fileName);
    vector<string> fromStringToExp(vector<string> commands);

    bool isOperator(string & c);

    bool isComper(char &c);
    bool is_number(char & s);
};


#endif //SECONDYEARPROJECT_BIU_LEXER_H
