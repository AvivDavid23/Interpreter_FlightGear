
#include "Number.h"

Number::Number(double value)  {
    this->value =value;
}

double Number::calculate() { return value; }

Number::~Number() {
delete(this);
}
