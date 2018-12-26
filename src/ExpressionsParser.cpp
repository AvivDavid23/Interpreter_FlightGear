#include <algorithm>
#include "ExpressionsParser.h"
#include "Command.h"

/**
 * @param exp
 * @param index
 * @return
 */
double ExpressionsParser::calculateFirstNum(const string& exp, unsigned long &index) {
    if (exp[index] != '(') {
        return (exp[index] - '0');
    }
    string val = "";
    ++index;
    while (exp[index] != ')') {
        val+=exp[index];
        index++;
    }
    if(val.find('.')== string::npos)
        return (double) atoi(val.c_str());
    val.erase(val.find_last_not_of('0')+1,string::npos);
    double number = atof(val.c_str());

    return number;
}
/**
 * @param c char.
 * @return check if the char is operator, return true if it is, 0 otherwise.
 */
bool ExpressionsParser::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
/**
 * @param type the sign
 * @param left expression.
 * @param right expression.
 * @return the expression with the currenct sign.
 */
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
/**
 * @param string in postfix .
 * @return the result of this expression.
 */
Expression *ExpressionsParser::postToExp(const string& exp) {
    stack<tuple<double, unsigned int>> numStack;
    stack<tuple<Expression *, unsigned int> > expStack;
    unsigned int time = 0;
    unsigned long index = 0;
    while (exp[index]) {
        // add new Number:
        if (!isOperator(exp[index])) {
            numStack.push(tuple<double,unsigned int>(calculateFirstNum(exp,index),time));
            ++index;
            ++time;
            // take two expressions and create one with them:
        } else if ((expStack.size() > 2 || (expStack.size()==2 && numStack.empty())) &&
                   ((numStack.empty() || ((time - get<1>(expStack.top()) == 1) &&
                                          (time - get<1>(numStack.top()) > 2))))) {
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
        if (!isdigit(item) && !isOperator(item) && item != ' ' && item != '(' && item != ')' && item!='.') return false;
    return true;
}
/**
 * @param expression the string
 * @return the calculate of the expression we build in postfix order.
 */
double ExpressionsParser::shuntingYardAlg(const string& expression) {
    if (!inputCheck(expression)) throw "Input Error!";
    // if its only a number:
    if (expression.find('(') == string::npos && expression.find(')') == string::npos &&
        expression.find('+') == string::npos && expression.find('-') == string::npos &&
        expression.find('/') == string::npos && expression.find('*') == string::npos)
        return atof(expression.c_str());
    // if number is only a negative number
    if(checkNeg(expression))
        return atof(expression.c_str());
    map<char, int> precedences;
    precedences['+'] = 1;
    precedences['-'] = 2;
    precedences['*'] = 3;
    precedences['/'] = 4;
    // from here, it's just alg' of dijkstra.
    stack<char> stack1;
    queue<char> queue2;
    queue2.push('(');
    queue<char> queue1;
    for (int i = 0; i < expression.length(); ++i) {
        if(expression[i] == '.') {
            queue2.push(expression[i]);
            continue;
        }
        if (isdigit(expression[i])) {
            queue2.push(expression[i]);
            // if the number is bigger the  2
            if (i < expression.length() && ((!isdigit(expression[i + 1])) && expression[i+1] != '.')) {
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
                while (!stack1.empty() && precedences[stack1.top()] >= precedences[expression[i]] &&
                       expression[i] != ' ') {
                    queue1.push(stack1.top());
                    stack1.pop();
                }
                if(expression[i] == '-' && (i==0)) {
                    queue1.push('0');
                    stack1.push(expression[i]);
                }
                else if(expression[i] == '-' && (!isdigit(expression[i-1]))) {
                    queue1.push('0');
                    stack1.push(expression[i]);
                }

                else if(expression[i]!= ' ')
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
   Expression * expression1 = postToExp(newExp);
    double var =  expression1->calculate();
     delete expression1 ;
        return var;
}
/**
 * @param exp string
 * @return new string that can be calculate in shunting yard.
 */
string ExpressionsParser::varsExtrication(const string &exp) {
    const char *pExp = exp.c_str();
    string newExp;
    string var;
    while (*pExp) {
        if (*pExp == '(' || *pExp == ')' || isdigit(*pExp) || isOperator(*pExp) || *pExp == ' ') {
            newExp += *pExp;
            ++pExp;
        } else {
            while (!(*pExp == '(' || *pExp == ')' || isOperator(*pExp) || *pExp == ' ') && *pExp) {
                var += *pExp;
                ++pExp;
            }
            globalMutex.lock();
            var = to_string(SymbolTable::instance()->getValue(var));
            var.erase ( var.find_last_not_of('0') + 1, std::string::npos ); // erase trailing zeros
            if(var.find('.') == var.length() - 1) var = var.substr(0, var.length() - 1);
            if (newExp.length() > 0 && newExp[newExp.length() - 1] == '-' && var[0] == '-')
                var = var.substr(1, var.length() - 1);
            newExp += var;
            globalMutex.unlock();
            var = "";
        }
    }
    return newExp;
}
/**
 * @param basic_string the string
 * @return true if's just a number negative, 0 otherwise.
 */
bool ExpressionsParser::checkNeg(const string &basic_string) {
    bool once = false;
    const char *c = basic_string.c_str();
    // if there is no '-' in the number
    if(c[0]!= '-') return false;
    // while the end of the number
    while(*c!= '\0' ){
        // check if the sign '-' shows once.
        if(*c == '-' && !once) once = true;
        else
            // if there is more things in the string, return false.
        if(isOperator(*c) && once) return false;
        c++;
    }
    return true;
}
