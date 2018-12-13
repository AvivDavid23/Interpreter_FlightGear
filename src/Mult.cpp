
#include "Mult.h"

Mult::Mult(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Mult::calculate() { return left->calculate() * right->calculate();
                                                                                                                                      0);}