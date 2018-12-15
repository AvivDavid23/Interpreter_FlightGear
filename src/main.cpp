
#include <fstream>
#include "Parser.h"
#include "Shunting-Yard.h"
#include "OpenServerCommand.h"
#define TEXT "file.txt"
/**
 * Runs on the file script, creates vector which each value has a string which represent a line
 * @param fileName name of the file
 * @return the lines vector
 */
vector<string> lexer(const string &fileName) {
    vector<string> vector;
    string tmp;
    fstream file;
    if (!file.is_open()) {
        file.open(fileName, fstream::in | fstream::app);
    }
    while (getline(file, tmp)) vector.push_back(tmp);
    file.close();
    return vector;
}

int main() {
    vector<string> vec;
    vec.emplace_back("test");
    vec.emplace_back("5401");
    vec.emplace_back("20/2");
    map<string, double>s;
    unsigned int a = 0;
    OpenServerCommand command(s, a);
    command.execute(vec, 0);
    while(true){

    }
    return 0;
}