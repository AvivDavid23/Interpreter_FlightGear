
#include "Div.h"

Div::Div(Expression *right, Expression *left) : BinaryExpression(right, left) {}

double Div::calculate() { return left->calculate() / right->calculate(); }