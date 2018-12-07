
#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H

#include "BinaryExpression.h"

/**
 * An addition expression
 */
class Plus : protected BinaryExpression {

public:

    Plus(Expression *right, Expression *left);

    double calculate();
};


#endif //PROJECT_PLUS_H
