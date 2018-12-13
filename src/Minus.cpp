
#include "Minus.h"
Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Minus::calculate() { return left->calculate() - right->calculate();}
