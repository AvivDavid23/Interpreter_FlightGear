//
// Created by dvir on 12/17/18.
//


#include "Lexer.h"
/**
* Runs on the file script, creates vector which each value has a string which represent a line
* @param fileName name of the file
* @return the lines vector
*/
vector<string> Lexer::active(const string &fileName) {
    createTable();
    vector<string> vector;
    string tmp;
    fstream file;
    if (!file.is_open()) {
        file.open(fileName, fstream::in | fstream::app);
    }
    while (file >> tmp) {
            vector.push_back(tmp);
    }
    file.close();
    return vector;
}

void Lexer::createTable() {
    this->parameters["connect"] = 2;
}