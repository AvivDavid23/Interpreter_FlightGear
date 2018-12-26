
#include <iostream>
#include "Number.h"

Number::Number(double value)  {
    this->value =value;
}
/**
 * @return the value
 */
double Number::calculate() { return value; }

Number::~Number() {}
