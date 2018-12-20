//
// Created by dvir on 12/17/18.
//


#include <iostream>
#include <sstream>
#include "Lexer.h"
/**
* Runs on the file script, creates vector which each value has a string which represent a line
* @param fileName name of the file
* @return the lines vector
*/
vector<string> Lexer::active(const string &fileName) {
    vector<string> vector;
    string tmp;
    fstream file;
    if (!file.is_open()) {
        file.open(fileName, fstream::in | fstream::app);
    }
    while (getline(file,tmp)) {
        vector.push_back(tmp);
    }
    file.close();
    return fromStringToExp(vector);
}
/*
 *  for(char& c : tmp)
          cout<<c << endl;
 */

vector<string> Lexer::fromStringToExp(vector<string> commands) {
    vector<string> words;
    bool check;
    string s;
    for (auto const item:commands) {
        if (item.find('=') != std::string::npos) { // find {
            check = false;
            std::stringstream ss(item);
            while (std::getline(ss, s, '=')) {
                std::stringstream sd(s);
                while (std::getline(sd, s, ' ')) {
                    words.push_back(s);
                }
                if (!check) {
                    check = true;
                    words.push_back("=");
                }
            }
        } else {
            std::stringstream ss(item);
            string help;
            while (std::getline(ss, s, ' ')) {
                if(s!="" && isdigit(s.at(0)) && !help.empty() && isdigit(help.at(help.size()-1))) {
                    // help+=s;
                    words.push_back(help);
                    help = "";
                    words.push_back(s);
                }
                else if(s!="" && isdigit(s.at(0)) && !ss.eof()) {
                     help += s;
                    }
                else if(!help.empty() && isOperator(s))
                    help+=s;
                else
                words.push_back(s);
            }
        }
    }
    vector<string> final;
    for (auto const &item:words) {
        if(item == "") continue;
        final.push_back(item);
    }
    return final;
}

bool Lexer::isOperator(string & c) {
    return(c == "+" || c == "-" || c == "*" || c == "=" || c == "/"  );
}
