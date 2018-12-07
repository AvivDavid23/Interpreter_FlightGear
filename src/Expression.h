
#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H
#include <vector>
#include <map>
using namespace std;
/**
 * Expression Interface
 */
class Expression {
public:
    virtual double calculate() = 0;
};

#endif //PROJECT_EXPRESSION_H
