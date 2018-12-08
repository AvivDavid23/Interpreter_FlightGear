
#ifndef SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
#define SECONDYEARPROJECT_BIU_SHUNTING_YARD_H

#include <iostream>
#include "queue"
#include "stack"
#include "Expression.h"

using namespace std;


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
    // 'reverse' queue to a string
    stack<char> stack2;
    while (!queue1.empty()) {
        stack2.push(queue1.front());
        queue1.pop();
    }
    string newExp;
    while (!stack2.empty()) {
        newExp += stack2.top();
        stack2.pop();
    }
    /**
     * From here, calculate the value of the expression:
     */
    stack<double >stack3;
    for (long j = newExp.length() - 1; j >= 0; --j) {
        if (isdigit(newExp[j])) stack3.push(newExp[j] - '0');
        else {
            double o1 = stack3.top();
            stack3.pop();
            double o2 = stack3.top();
            stack3.pop();
            switch (newExp[j]) {
                case '+':
                    stack3.push(o1 + o2);
                    break;
                case '-':
                    stack3.push(o1 - o2);
                    break;
                case '*':
                    stack3.push(o1 * o2);
                    break;
                case '/':
                    stack3.push(o1 / o2);
                    break;
                default:
                    break;
            }
        }
    }
    // case where the whole algorithm got only a number:
    if (stack3.size() > 1) {
        string temp;
        while (!stack3.empty()) {
            temp += stack3.top() + '0';
            stack3.pop();
        }
        // reverse and calculate string:
        double val = 0;
        for (long i = temp.length() - 1; i >= 0; --i) {
            val *= 10;
            val += temp[i] - '0';
        }
        return val;
    } else return stack3.top();
}

#endif //SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
