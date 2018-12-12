

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
#include "tuple"
#include <algorithm>

using namespace std;


/**
 *
 * @param exp the expression.
 * @param index start index
 * @return the value of the first number in exp which begins at index.
 */
inline double calculateFirstNum(string exp, unsigned long &index) {
    if (exp[index] != '(') {
        return (exp[index] - '0');
    }
    double val = 0;
    ++index;
    while (exp[index] != ')') {
        val *= 10;
        val += exp[index] - '0';
        index++;
    }
    return val;
}

/**
 * @param c char
 * @return true if char is an operator
 */
inline bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


inline Expression *createExpression(char type, Expression *left, Expression *right) {
    switch (type) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Mult(left, right);
        case '/':
            return new Div(left, right);
    }
}

/**
 * Transfers the string into an Expression
 * @param exp string expression
 * @return expression
 */
inline Expression *postToExp(string exp) {
    stack<tuple<double, unsigned int>> numStack;
    stack<tuple<Expression *, unsigned int> > expStack;
    unsigned int time = 0;
    unsigned long index = 0;
    while (exp[index]) {
        // add new Number:
        if (!isOperator(exp[index])) {
            numStack.push(tuple<double, unsigned int>(calculateFirstNum(exp, index), time));
            ++index;
            ++time;
        }
            // take two expressions and create one with them:
        else if (expStack.size() >= 2 && isOperator(exp[index])
        && (numStack.empty() || time - get<1>(expStack.top()) == 1)) {
            Expression *ex2 = get<0>(expStack.top());
            expStack.pop();
            Expression *ex1 = get<0>(expStack.top());
            expStack.pop();
            expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], ex1, ex2), time));
            ++index;
            ++time;
        } else {
            // take first two numbers and push new Expression:
            if ((expStack.empty() || time - get<1>(expStack.top()) > 2)&& !numStack.empty()) {
                double v2 = get<0>(numStack.top());
                numStack.pop();
                double v1 = get<0>(numStack.top());
                numStack.pop();
                expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], new Number(v1),
                                                                                 new Number(v2)), time));
                ++index;
                ++time;
            } else {
                tuple<double, unsigned int> numberTup = numStack.top();
                double val = get<0>(numberTup); // value
                numStack.pop();
                tuple<Expression *, unsigned int> expressionTup = expStack.top();
                Expression *expression = get<0>(expressionTup); // expression
                expStack.pop();
                // check who came first, if number, number will be on left side of the new operator. else right side
                if (get<1>(numberTup) > get<1>(expressionTup)) {
                    expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], expression,
                                                                                     new Number(val)), time));
                    ++index;
                    ++time;
                } else {
                    expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], new Number(val),
                                                                                     expression), time));
                    ++index;
                    ++time;
                }
            }
        }
    }
    return get<0>(expStack.top());
}

/**
 * implementation of Shunting Yard Algorithm
 * @param expression the expression ass a string
 * @return value of the expression
 */
static inline double shuntingYardAlg(string expression) {
    map<char, int> precedences;
    precedences['+'] = 1;
    precedences['-'] = 2;
    precedences['*'] = 3;
    precedences['/'] = 4;
    stack<char> stack1;
    queue<char> queue2;
    queue2.push('(');
    queue<char> queue1;
    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            queue2.push(expression[i]);
            // if the number is bigger the  2
            if (i < expression.length() && !isdigit(expression[i + 1])) {
                queue2.push(')');
                if (queue2.size() > 3) {
                    while (!queue2.empty()) {
                        queue1.push(queue2.front());
                        queue2.pop();
                    }
                    queue2.push('(');
                } else {
                    while (!queue2.empty()) {
                        if (!(queue2.front() == ')' || queue2.front() == '('))
                            queue1.push(queue2.front());
                        queue2.pop();
                    }
                    queue2.push('(');
                }
            }
        } else {
            if (expression[i] == '(') {
                stack1.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!stack1.empty() && stack1.top() != '(') {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                stack1.pop();
            } else { // char is an operator:
                while (!stack1.empty() && precedences[stack1.top()] > precedences[expression[i]] &&
                       expression[i] != ' ') {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                if (expression[i] != ' ')
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
    return postToExp(newExp)->calculate();
}

#endif //SECONDYEARPROJECT_BIU_SHUNTING_YARD_H
