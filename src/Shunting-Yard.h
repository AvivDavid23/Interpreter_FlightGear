
#ifndef SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
#define SECONDYEARPROJECT_BIU_SHUNTING_YARD_H

#include <iostream>
#include "queue"
#include "stack"
#include "Expression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Number.h"

using namespace std;
/**
 * @param exp string expression
 * @return first operator index
 */
inline int firstOperatorIndex(string exp) {
    for (int i = 0; i < exp.length(); ++i) {
        if (!isdigit(exp[i])) return i;
    }
    return -1;
}

/**
 * @param exp string expression
 * @return expression
 */
inline Expression *prefixToExp(string exp) {
    if (exp.length() == 1) return new Number(exp[0] - '0');
    // TODO: FINISH FUNCTION
    if (exp.length() == 3) {
        switch (exp[2]) {
            case '+':
                return new Plus(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '-':
                return new Minus(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '*':
                return new Mult(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
            case '/':
                return new Div(new Number(exp[0] - '0'), new Number(exp[1] - '0'));
        }
    } else {
        if (!isdigit(exp[exp.length() - 1]) && firstOperatorIndex(exp) > 2) {
            switch (exp[exp.length() - 1]) {
                case '+':
                    return new Plus(new Number(exp[0] - '0'), prefixToExp(exp.substr(1, exp.length() - 2)));
                case '-':
                    return new Minus(new Number(exp[0] - '0'), prefixToExp(exp.substr(1, exp.length() - 2)));
                case '*':
                    return new Mult(new Number(exp[0] - '0'), prefixToExp(exp.substr(1, exp.length() - 2)));
                case '/':
                    return new Div(new Number(exp[0] - '0'), prefixToExp(exp.substr(1, exp.length() - 2)));
            }
        } else {
            switch (exp[exp.length() - 1]) {
                case '+':
                    return new Plus(prefixToExp(exp.substr(0, 3)), prefixToExp(exp.substr(3, exp.length() - 4)));
                case '-':
                    return new Minus(prefixToExp(exp.substr(0, 3)), prefixToExp(exp.substr(3, exp.length() - 4)));
                case '*':
                    return new Mult(prefixToExp(exp.substr(0, 3)), prefixToExp(exp.substr(3, exp.length() - 4)));
                case '/':
                    return new Div(prefixToExp(exp.substr(0, 3)), prefixToExp(exp.substr(3, exp.length() - 4)));
            }
        }

    }
}

/**
 * implementation of Shunting Yard Algorithm
 * @param expression the expression ass a string
 * @return value of the expression
 */
static inline double shuntingYardAlg(string expression) {
    map<char, int> precedences;
    precedences['+'] = precedences['-'] = 1;
    precedences['*'] = precedences['/'] = 2;
    stack<char> stack1;
    queue<char> queue1;
    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) queue1.push(expression[i]);
        else {
            if (expression[i] == '(') {
                stack1.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!stack1.empty() && stack1.top() != '(') {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                stack1.pop();
            } else { // char is an operator:
                while (!stack1.empty() && precedences[stack1.top()] > precedences[expression[i]]) {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                stack1.push(expression[i]);
            }
        }
    }
    // push rest in stack to queue
    while (!stack1.empty()) {
        queue1.push(stack1.top());
        stack1.pop();
    }
    // make a string
    string newExp;
    stack<char> stack2;
    while (!queue1.empty()) {
        newExp += queue1.front();
        queue1.pop();
    }
    /**
     * From here, calculate the value of the expression:
     */
    double val = prefixToExp(newExp)->calculate();

}

#endif //SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
