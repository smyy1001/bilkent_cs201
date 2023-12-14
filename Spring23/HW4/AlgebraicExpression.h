// Author: Sumeyye ACAR
// ID: 22103640
// Date: 30 May 2023
// File: AlgebraicExpression.h

// include:
#include <iostream>
#include <stack>

class AlgebraicExpression {};

// Global Function Prototypes
bool isOp( const char c );
bool isOpPar( const char c );
bool isClPar( const char c );
int priority( const char c );
std::string infix2postfix( const std::string exp );
double evaluatePostfix( const std::string exp );
