//
// Created by aviv on 1/9/19.
//

#ifndef SECONDYEARPROJECT_BIU_UTILS_H
#define SECONDYEARPROJECT_BIU_UTILS_H

#include <string>
#include <vector>

// class of useful general functions
class Utils {
public:
    static std::vector<std::string> splitByChar(std::string &input, char token) {
        unsigned long i = 0;
        std::vector<std::string> vec;
        std::string tmp;
        while (input[i]) {
            if (input[i] != ',') {
                tmp += input[i];
            } else {
                vec.emplace_back(tmp);
                tmp = "";
            }
            ++i;
        }
        return vec;
    }
};

#endif //SECONDYEARPROJECT_BIU_UTILS_H
