
#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H

#include "Expression.h"

/**
 * The basic class of an expression, which is only a number(value)
 */
class Number : public Expression {
    double value;

public:
    Number(double value);

    double calculate();

};


#endif //PROJECT_NUMBER_H
