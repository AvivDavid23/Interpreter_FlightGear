//
// Created by dvir on 12/17/18.
//

#ifndef SECONDYEARPROJECT_BIU_LEXER_H
#define SECONDYEARPROJECT_BIU_LEXER_H
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
class Lexer {
    map<string,int> parameters;
public:
    vector<string> active(const string &fileName);
    void createTable();
};


#endif //SECONDYEARPROJECT_BIU_LEXER_H
