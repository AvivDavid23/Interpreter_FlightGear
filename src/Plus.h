
#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H

#include "BinaryExpression.h"

/**
 * An addition expression
 */
class Plus : public BinaryExpression {

public:

    Plus(Expression *left, Expression *right);

    double calculate();
};


#endif //PROJECT_PLUS_H
