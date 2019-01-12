//
// Created by aviv on 1/9/19.
//

#ifndef SECONDYEARPROJECT_BIU_UTILS_H
#define SECONDYEARPROJECT_BIU_UTILS_H

#include <string>
#include <vector>
#include <sstream>

// class of useful general functions
class Utils {
public:
    static std::vector<std::string> split(std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};

#endif //SECONDYEARPROJECT_BIU_UTILS_H
