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
/**
 * @param the lines in the file.
 * @return vector of words in the right order
 */
vector<string> Lexer::fromStringToExp(vector<string> commands) {
    vector<string> words;
    bool check;
    string s;
    // goes all the lines in the file.
    for (auto const item:commands) {
        // if there is a '=' in the line.
        if (item.find('=') != std::string::npos) {
            check = false;
            std::stringstream ss(item);
            // split by '='.
            while (std::getline(ss, s, '=')) {
                std::stringstream sd(s);
                // split by space.
                while (std::getline(sd, s, ' ')) {
                    words.push_back(s);
                }
                if (!check) {
                    check = true;
                    // if there is no '=' in the vector of words, put it.
                    words.push_back("=");
                }
            }
            // if there is no '=' in line
        } else {
            std::stringstream ss(item);
            string help;
            // split by space.
            while (std::getline(ss, s, ' ')) {
                // if help isn't empty and s isn't empty and s is a number and the last index of help is also a number
                if(!s.empty() && isdigit(s.at(0)) && !help.empty() && isdigit(help.at(help.size()-1))) {
                    // push the help
                    words.push_back(help);
                    // empty the string help.
                    help = "";
                    // push the string.
                    words.push_back(s);
                }
                // if s is not a space, and it's number and we didn't reach the  final of the line
                else if(!s.empty() && isdigit(s.at(0)) && !ss.eof()) {
                     help += s;
                    }
                // if help isn't empty and it isn't operator , just concatenating the string to help.
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
    // return the vector of string.
    return final;
}
/**
 * @param c the expression.
 * @return return 1 if is operator, 0 otherwise.
 */
bool Lexer::isOperator(string & c) {
    return(c == "+" || c == "-" || c == "*" || c == "=" || c == "/"  );
}
