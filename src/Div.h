
#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H

#include "BinaryExpression.h"
/**
 * A division expression
 */
class Div : public BinaryExpression {
public:
    Div(Expression *left, Expression *right);

    double calculate();
};


#endif //PROJECT_DIV_H
