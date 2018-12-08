//
// Created by dvir on 12/7/18.
//

#ifndef PROJECT_MINUS_H
#define PROJECT_MINUS_H

#include "BinaryExpression.h"

/**
 * An subtraction expression
 */
class Minus : public BinaryExpression {

public:

    Minus(Expression *right, Expression *left);

    double calculate();
};


#endif //PROJECT_MINUS_H
