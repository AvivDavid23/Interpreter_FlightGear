//
// Created by dvir on 12/15/18.
//

#include "ConditionParser.h"
#include "Parser.h"

void ConditionParser::execute(const vector<string> &line) {
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
    setUpCommands(line);
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
 * @param i index of the array of words.
 */
ConditionParser::ConditionParser(unsigned int &i) {
this->index= i ;
}

void ConditionParser::setUpCommands(const vector<string> &words1) {
    unsigned int place = index;
        while(words1[place] != "{") ++place;
        ++place;
        while(words1[place] != "}") {
            // auto it = parser..find(words1[place]);
            //if(it!= parser.commandsTable.end()) {
                //this->expression.push_back(it->second);
            }
            ++place;
        }
//}

