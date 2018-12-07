
#include "Mult.h"

Mult::Mult(Expression *right, Expression *left) : BinaryExpression(right, left) {}

double Mult::calculate() { return right->calculate() * left->calculate();}