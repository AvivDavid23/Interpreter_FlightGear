
#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"

/**
 * A binary expression, which holds two expressions
 */
class BinaryExpression : public Expression {
protected:
    Expression *right;
    Expression *left;

public:
    BinaryExpression(Expression *left, Expression *right) {}
};

#endif //PROJECT_BINARYEXPRESSION_H
