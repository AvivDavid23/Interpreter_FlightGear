
#ifndef PROJECT_MULT_H
#define PROJECT_MULT_H

#include "BinaryExpression.h"
/**
 * A multiplication expression
 */
class Mult : protected BinaryExpression{
public:
    Mult(Expression *right, Expression *left);

    double calculate();
};


#endif //PROJECT_MULT_H
