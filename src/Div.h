
#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H

#include "BinaryExpression.h"
/**
 * A division expression
 */
class Div : public BinaryExpression {
public:
    Div(Expression *right, Expression *left);

    double calculate();
};


#endif //PROJECT_DIV_H
