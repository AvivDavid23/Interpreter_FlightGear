
#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <iostream>
#include "ConditionParser.h"
#include "Parser.h"
/**
 * A command which runs if a condition is satisfied
 */
class IfCommand : public ConditionParser {
public:
    void execute(const vector<string> &words);

    IfCommand(unsigned int &index);
};


#endif //PROJECT_IFCOMMAND_H
