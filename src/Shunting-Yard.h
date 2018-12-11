

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
#include <algorithm>

using namespace std;

/**
 * @param exp string expression
 * @return first operator index
 */
inline unsigned long firstOperatorIndex(string exp) {
    for (unsigned long i = 0; i < exp.length(); ++i) {
        if (!isdigit(exp[i]) && (!(exp[i] == '(' || exp[i] == ')'))) return i;
    }
    return 0;
}

/**
 *
 * @param exp the expression.
 * @return the value of the first number in exp.
 */
inline double calculateFirstNum(string exp) {
    if (exp[0] != '(')
        return (exp[0] - '0');
    double val = 0;
    int i = 1;
    while (exp[i] != ')') {
        val *= 10;
        val += exp[i] - '0';
        i++;
    }
    return val;
}

inline int howManyOperators(string exp) {
    int count = 0;
    for (char i : exp) {
        if (!isdigit(i) && (!(i == '(' || i == ')'))) count++;
    }
    return count;
}

/**
 *
 * @param exp the expression
 * @return how much to move the index
 */
inline unsigned long howMuchToDrop(string exp) {
    unsigned long i = 1;
    if (exp[0] != '(') return i;
    while (exp[i] != ')') ++i;
    return i + 1;
}

/**
 * In case where we have something like :25+8/5-, we want to extract (5) in order to give it as second parameter
 * to Minus expression
 * @param exp expression
 * @param indexEnd the index where the numbers ends.
 * @return the value of the number.
 *
 */
inline double exctractNum(string exp, unsigned long indexEnd) {
    if (exp[indexEnd] != ')') return exp[indexEnd] - '0';
    string num;
    while (exp[indexEnd] != '(') num += exp[indexEnd];
    num += '(';
    reverse(num.begin(), num.end());
    return calculateFirstNum(num);
}

int manyNumber(string exp) {
    int count = 0, i = 0;
    while (isdigit(exp[i] - '0') || exp[i] == '(' || exp[i] == ')')
        if (exp[i] != '(') count++;
        else {
            while (exp[i] != ')') i++;
            i++,count++;
        }
}
/**
 * @param exp string expression
 * @return expression
 */
inline Expression *postToExp(string exp) {
    // case where we got only a number:
    if (firstOperatorIndex(exp) == -1) return new Number(calculateFirstNum(exp));
    // TODO: FINISH FUNCTION
    if (howManyOperators(exp) == 1) {
        switch (exp.at(exp.length() - 1)) {
            case '+':
                return new Plus(new Number(calculateFirstNum(exp)),
                                new Number(calculateFirstNum(
                                        exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1))));
            case '-':
                return new Minus(new Number(calculateFirstNum(exp)),
                                 new Number(calculateFirstNum(
                                         exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1))));
            case '*':
                return new Mult(new Number(calculateFirstNum(exp)),
                                new Number(calculateFirstNum(
                                        exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1))));
            case '/':
                return new Div(new Number(calculateFirstNum(exp)),
                               new Number(calculateFirstNum(
                                       exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1))));
        }
    } else {
        if (!isdigit(exp[exp.length() - 1])) {
            if (manyNumber(exp) > 2) {
                switch (exp[exp.length() - 1]) {
                    case '+':
                        return new Plus(new Number(calculateFirstNum(exp)),
                                        postToExp(
                                                exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1)));
                    case '-':
                        return new Minus(new Number(calculateFirstNum(exp)),
                                         postToExp(exp.substr(howMuchToDrop(exp),
                                                              exp.length() - howMuchToDrop(exp) - 1)));
                    case '*':
                        return new Mult(new Number(calculateFirstNum(exp)),
                                        postToExp(
                                                exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1)));
                    case '/':
                        return new Div(new Number(calculateFirstNum(exp)),
                                       postToExp(
                                               exp.substr(howMuchToDrop(exp), exp.length() - howMuchToDrop(exp) - 1)));
                }
            } else {
                if (isdigit(exp[exp.length() - 2]) || exp[exp.length() - 2] == ')') {
                    double exctracted = exctractNum(exp, exp.length() - 2);
                    switch (exp[exp.length() - 1]) {
                        case '+':
                            return new Plus(postToExp(exp.substr(0, exp.length() - to_string(exctracted).length() - 1))
                                    , new Number(exctracted));
                        case '-':
                            return new Minus(postToExp(exp.substr(0, exp.length() - to_string(exctracted).length() - 1))
                                    , new Number(exctracted));
                        case '*':
                            return new Mult(postToExp(exp.substr(0, exp.length() - to_string(exctracted).length() - 1))
                                    , new Number(exctracted));
                        case '/':
                            return new Div(postToExp(exp.substr(0, exp.length() - to_string(exctracted).length() - 1))
                                    , new Number(exctracted));
                    }
                } else{
                    switch (exp[exp.length() - 1]) {
                        case '+':
                            return new Plus(postToExp(exp.substr(0, firstOperatorIndex(exp))),
                                    postToExp(exp.substr(firstOperatorIndex(exp) + 1,
                                            exp.length() - firstOperatorIndex(exp) - 2)));
                        case '-':
                            return new Minus(postToExp(exp.substr(0, firstOperatorIndex(exp))),
                                             postToExp(exp.substr(firstOperatorIndex(exp) + 1,
                                                                  exp.length() - firstOperatorIndex(exp) - 2)));
                        case '*':
                            return new Mult(postToExp(exp.substr(0, firstOperatorIndex(exp))),
                                            postToExp(exp.substr(firstOperatorIndex(exp) + 1,
                                                                 exp.length() - firstOperatorIndex(exp) - 2)));
                        case '/':
                            return new Div(postToExp(exp.substr(0, firstOperatorIndex(exp))),
                                           postToExp(exp.substr(firstOperatorIndex(exp) + 1,
                                                                exp.length() - firstOperatorIndex(exp) - 2)));
                    }
                }
            }
        }
    }
    return NULL;
}

/**
 * implementation of Shunting Yard Algorithm
 * @param expression the expression ass a string
 * @return value of the expression
 */
static inline double shuntingYardAlg(string expression) {
    map<char, int> precedences;
    bool biggerThen9 = false;
    precedences['+'] = precedences['-'] = 1;
    precedences['*'] = precedences['/'] = 2;
    stack<char> stack1;
    queue<char> quene2;
    quene2.push('(');
    queue<char> queue1;
    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            quene2.push(expression[i]);
            // if the number is bigger the  2
            if (i < expression.length() && !isdigit(expression[i + 1])) {
                quene2.push(')');
                if (quene2.size() > 3) {
                    while (!quene2.empty()) {
                        queue1.push(quene2.front());
                        quene2.pop();
                    }
                    quene2.push('(');
                } else {
                    while (!quene2.empty()) {
                        if (!(quene2.front() == ')' || quene2.front() == '('))
                            queue1.push(quene2.front());
                        quene2.pop();
                    }
                    quene2.push('(');
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
