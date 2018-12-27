
#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H

#include "BinaryExpression.h"

/**
 * An addition expression
 */
class Plus : public BinaryExpression {

public:

    Plus(Expression *left, Expression *right);
/**
 * @return the calculate between the expression.
 */
    double calculate();

    virtual ~Plus();
};


#endif //PROJECT_PLUS_H
