
#include "Minus.h"
Minus::Minus(Expression *right, Expression *left) : BinaryExpression(right, left) {}

double Minus::calculate() { return right->calculate() - left->calculate();}