
#include <iostream>
#include "Minus.h"
Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Minus::calculate() { return left->calculate() - right->calculate();}

Minus::~Minus() {
    std::cout << " proof the destructor has been called";
    delete right;
    delete left;
}
