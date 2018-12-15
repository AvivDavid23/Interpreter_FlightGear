
#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <iostream>
#include "ConditionParser.h"
#include "Parser.h"
/**
 * A command which runs if a condition is satisfied
 */
class IfCommand : public ConditionParser {
    map<string,double> &commandList;
    unsigned int &index;
public:
    int execute(const vector<string> &words, unsigned int index);

    IfCommand(unsigned int &index,map<string, double> &commandList);

};


#endif //PROJECT_IFCOMMAND_H
