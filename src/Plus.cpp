
#include "Plus.h"

Plus::Plus(Expression *right, Expression *left) : BinaryExpression(right, left) {}

double Plus::calculate() { return right->calculate() + left->calculate();}