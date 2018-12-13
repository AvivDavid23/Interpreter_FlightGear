
#include "Div.h"

Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Div::calculate() {
    return left->calculate() / right->calculate();
}