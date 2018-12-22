//
// Created by dvir on 12/15/18.
//

#include "ConditionParser.h"
#include "Parser.h"
/**
 * @param line the words
 */
bool ConditionParser::execute(const vector<string> &line) {
    index++;
    // left expression until the operator
    string leftExpression;
    // check in which index has operator
    while (!checkOperator(line[index])) {
        leftExpression += line[index];
        leftExpression = ExpressionsParser::varsExtrication(leftExpression);
        index++;
    }
    int count = index; // operator index
    string rightExpression;
    ++index;
    // create the right expression until the end of the condition.
     rightExpression += line[index];
    rightExpression = ExpressionsParser::varsExtrication(rightExpression);
    if (line[count] == ">") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) > ExpressionsParser::shuntingYardAlg(rightExpression));
    }
    if (line[count] == ">=") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) >= ExpressionsParser::shuntingYardAlg(rightExpression));
    }
    if (line[count] == "==") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) == ExpressionsParser::shuntingYardAlg(rightExpression));
    }
    if (line[count] == "!=") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) != ExpressionsParser::shuntingYardAlg(rightExpression));
    }
    if (line[count] == "<") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) <ExpressionsParser::shuntingYardAlg(rightExpression));
    }
    if (line[count] == "<=") {
        return (ExpressionsParser::shuntingYardAlg(leftExpression) <= ExpressionsParser::shuntingYardAlg(rightExpression));
    }
}
/**
 * @param charOperator the string.
 * @return 1 if the string is operator, 0 otherwise.
 */
bool ConditionParser::checkOperator(const string &charOperator) {
    return (charOperator == ">" || charOperator == ">=" || charOperator == "==" || charOperator == "!=" ||
            charOperator == "<" || charOperator == "<=");
}
/**
 * @param i index of the array of words.return
 */
ConditionParser::ConditionParser(unsigned int &i) {
this->index= i ;
}


