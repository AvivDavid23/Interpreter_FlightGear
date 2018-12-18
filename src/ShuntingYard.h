
#ifndef SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
#define SECONDYEARPROJECT_BIU_SHUNTING_YARD_H

#include <iostream>
#include "queue"
#include "stack"
#include "Expression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Number.h"
#include "tuple"
#include <algorithm>

using namespace std;

class ShuntingYard {
/**
 *
 * @param exp the expression.
 * @param index start index
 * @return the value of the first number in exp which begins at index.
 */
    static double calculateFirstNum(string exp, unsigned long &index);

/**
 * @param c char
 * @return true if char is an operator
 */
    static bool isOperator(char c);

/**
 * @param type operation for exp
 * @param left left exp
 * @param right right exp
 * @return desired expression, based on the operation
 */
    static Expression *createExpression(char type, Expression *left, Expression *right);

/**
 * Transfers the string into an Expression
 * @param exp string expression
 * @return expression
 */
    static Expression *postToExp(string exp);

/**
 * Input check
 * @param str string
 * @return true if good, else false
 */
    static bool inputCheck(string str);

public:
/**
 * implementation of Shunting Yard Algorithm
 * @param expression the expression ass a string
 * @return value of the expression
 */
    static double shuntingYardAlg(string expression);
};

#endif //SECONDYEARPROJECT_BIU_SHUNTING_YARD_H