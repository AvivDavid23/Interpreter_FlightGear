
#include "ExpressionsParser.h"


double ExpressionsParser::calculateFirstNum(const string& exp, unsigned long &index) {
    if (exp[index] != '(') {
        return (exp[index] - '0');
    }
    double val = 0;
    bool neg = false;
    ++index;
    while (exp[index] != ')') {
        if (exp[index] == '-'){
          neg = true;
            ++index;
            continue;
        }
        val *= 10;
        val += exp[index] - '0';
        ++index;
    }
    if(neg) return val*(-1);
    return val;
}

bool ExpressionsParser::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Expression *ExpressionsParser::createExpression(char type, Expression *left, Expression *right) {
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

Expression *ExpressionsParser::postToExp(const string& exp) {
    stack<tuple<double, unsigned int>> numStack;
    stack<tuple<Expression *, unsigned int> > expStack;
    unsigned int time = 0;
    unsigned long index = 0;
    while (exp[index]) {
        // add new Number:
        if (!isOperator(exp[index])) {
            tuple<double,unsigned int> x;
            x = make_tuple(calculateFirstNum(exp,index),time);
            ++index;
            ++time;
            //if(exp[index] == '-' && (!isOperator(exp[index+1]))) {
                //get<0>(x) =  get<0>(x) * -1;
                //index++;
            //}
            numStack.push(x);
            // take two expressions and create one with them:
        } else if (expStack.size() >= 2 && ((numStack.empty() || ((time - get<1>(expStack.top()) == 1)
                                                                  && (time - get<1>(numStack.top()) > 2))))) {
            Expression *ex2 = get<0>(expStack.top());
            expStack.pop();
            Expression *ex1 = get<0>(expStack.top());
            expStack.pop();
            expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], ex1, ex2), time));
            ++index;
            ++time;
        } else {
            // take first two numbers and push new Expression:
            if ((expStack.empty() || time - get<1>(expStack.top()) > 2) && !numStack.empty()) {
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
                } else {
                    expStack.push(tuple<Expression *, unsigned int>(createExpression(exp[index], new Number(val),
                                                                                     expression), time));
                }
                ++index;
                ++time;
            }
        }
    }
    while(!numStack.empty()) {
        tuple<double, unsigned int> numberTup = numStack.top();
        double val = get<0>(numberTup); // value
        numStack.pop();
        Expression *expression;
        if(!expStack.empty()) {
            tuple<Expression *, unsigned int> expressionTup = expStack.top();
             expression = get<0>(expressionTup);
             expStack.pop();
             char sign = '-';
             if(val < 0 ) sign= '+';
            expStack.push(tuple<Expression *, unsigned int>(createExpression(sign, expression,
                                                                             new Number(val)), time));
        }// expression
        else {
            double val2 = get<0>(numStack.top());
            numStack.pop();
            expression = new Number(val2);
            expStack.push(tuple<Expression *, unsigned int>(createExpression('+', expression,
                                                                             new Number(val)), time));
        }
    }
    return get<0>(expStack.top()); // the full exp is at the top of the stack
}

bool ExpressionsParser::inputCheck(const string& str) {
    for (auto item : str)
        if (!isdigit(item) && !isOperator(item) && item != ' ' && item != '(' && item != ')') return false;
    return true;
}

double ExpressionsParser::shuntingYardAlg(const string& expression) {
    if (!inputCheck(expression)) throw "Input Error!";
    // if its only a number:
    if (expression.find('(') == string::npos && expression.find(')') == string::npos &&
        expression.find('+') == string::npos && expression.find('-') == string::npos &&
        expression.find('/') == string::npos && expression.find('*') == string::npos)
        return atof(expression.c_str());
    if(checkNeg(expression))
        return atof(expression.c_str());
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
                    if(expression[i] == '-' && isdigit(expression[i+1]) && (stack1.empty() || stack1.top() == '(')) {
                        queue2.push(expression[i]);
                    }
                    else
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

string ExpressionsParser::varsExtrication(const string &exp) {
    const char *pExp = exp.c_str();
    string newExp;
    string var;
    while (*pExp) {
        if (*pExp == '(' || *pExp == ')' || isdigit(*pExp) || isOperator(*pExp) || *pExp == ' ') {
            newExp += pExp;
            ++pExp;
        } else {
            while (!(*pExp == '(' || *pExp == ')' || isOperator(*pExp))) {
                var += pExp;
                ++pExp;
            }
            globalMutex.lock();
            newExp += to_string(SymbolTable::instance()->getValue(var));
            var = "";
        }
    }
    return newExp;
}

bool ExpressionsParser::checkNeg(const string &basic_string) {
    bool once = false;
    const char *c = basic_string.c_str();
    if(c[0]!= '-') return false;
    while(*c!= '\0' ){
        if(*c == '-' && !once) once = true;
        else
            if(isOperator(*c) && once) return false;
                c++;
    }
    return true;
}
