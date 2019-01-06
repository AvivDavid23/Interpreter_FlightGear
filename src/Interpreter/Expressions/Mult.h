
#ifndef PROJECT_MULT_H
#define PROJECT_MULT_H

#include "BinaryExpression.h"
/**
 * A multiplication expression
 */
class Mult : public BinaryExpression{
public:
    Mult(Expression *left, Expression *right);
/**
 * @return the calculate between the expression.
 */
    double calculate();

    virtual ~Mult();
};


#endif //PROJECT_MULT_H
