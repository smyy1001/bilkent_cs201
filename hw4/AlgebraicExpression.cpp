// Author: Sumeyye ACAR
// ID: 22103640
// Date: 30 May 2023
// File: AlgebraicExpression.cpp

#include "AlgebraicExpression.h"

// Function Implementations
bool isOp( const char c ) {return (c == '+' || c == '-' || c == '*' || c == '/');}
bool isOpPar( const char c ) {return (c == '(');}
bool isClPar( const char c ) {return (c == ')');}
int priority( const char c ) { // to determine the precedence of an operator
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}


// Method to convert infix expressions to postfix expressions
std::string infix2postfix( const std::string exp ) { // infix to postfix
    std::stack<char> stack;
    std::string postfix; // output std::string
    
    for (char c : exp) {
        if (isdigit(c)) { postfix += c; } // add operands to the output
    
        else if (isOpPar(c)) { stack.push(c); } // push opening parenthesis onto the stack

        else if (isClPar(c)) {  // If closing parenthesis appears, pop operators and add to output
                                // stop when an opening parenthesis comes
            while (!stack.empty() && !(isOpPar(stack.top()))) {
                
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // delete the opening parenthesis
        }

        else if (isOp(c)) { // when an operator iis encountered, pop operators from stack
                            // and add to output if they have priority
            while (!stack.empty() && (priority(stack.top()) >= priority(c))) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    } // end of for loop
    
    while (!stack.empty()) { // add the remaining operators from the stack to to the output
        postfix += stack.top();
        stack.pop();
    }
    return postfix; // postfix version of the input expression
} // end of infix2postfix()


// Method for Evaluate Postfix Expressions
double evaluatePostfix( const std::string exp ) {
    std::stack<double> stack;

    for(char c : exp) {
        if(isdigit(c)) { stack.push(c - '0');} // Convert char to double
        else if (isOp(c)) {
            
            double data_1 = stack.top();
            stack.pop();

            double data_2 = stack.top(); 
            stack.pop();

            double result;
            switch (c) {
                case '+':
                    result = data_2 + data_1;
                    break;
                case '-':
                    result = data_2 - data_1;
                    break;
                case '*':
                    result = data_2 * data_1;
                    break;
                case '/':
                    result = data_2 / data_1;
                    break;
            }
            stack.push(result);        
        }
    }
    return stack.top(); // result will be the top element
} // end of evaluatePostfix()