
#ifndef PROJECT_MULT_H
#define PROJECT_MULT_H

#include "BinaryExpression.h"
/**
 * A multiplication expression
 */
class Mult : public BinaryExpression{
public:
    Mult(Expression *left, Expression *right);

    double calculate();
};


#endif //PROJECT_MULT_H
