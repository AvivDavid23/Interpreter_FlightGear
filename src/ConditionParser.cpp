//
// Created by dvir on 12/15/18.
//

#include "ConditionParser.h"

int ConditionParser::execute(const vector<string> &line, unsigned int i) {
    index = i;
    index++;
    // left expression until the operator
    string leftExpression;
    // check in which index has operator
    while (!checkOperator(line[index])) {
        leftExpression += line[index];
        index++;
    }
    int count = index; // operator index
    string rightExpression;
    ++index;
    // create the right expression until the end of the condition.
     rightExpression += line[index];
    if (line[count] == ">") {
        return (shuntingYardAlg(leftExpression) > shuntingYardAlg(rightExpression));
    }
    if (line[count] == ">=") {
        return (shuntingYardAlg(leftExpression) >= shuntingYardAlg(rightExpression));
    }
    if (line[count] == "==") {
        return (shuntingYardAlg(leftExpression) == shuntingYardAlg(rightExpression));
    }
    if (line[count] == "!=") {
        return (shuntingYardAlg(leftExpression) != shuntingYardAlg(rightExpression));
    }
    if (line[count] == "<") {
        return (shuntingYardAlg(leftExpression) < shuntingYardAlg(rightExpression));
    }
    if (line[count] == "<=") {
        return (shuntingYardAlg(leftExpression) <= shuntingYardAlg(rightExpression));
    }
}

bool ConditionParser::checkOperator(const string &charOperator) {
    return (charOperator == ">" || charOperator == ">=" || charOperator == "==" || charOperator == "!=" ||
            charOperator == "<" || charOperator == "<=");
}

ConditionParser::ConditionParser(unsigned int &i) {
this->index= i ;
}

