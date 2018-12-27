
#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}


double Plus::calculate() { return left->calculate() + right->calculate();
}

Plus::~Plus() {
    delete left;
    delete right;
}
