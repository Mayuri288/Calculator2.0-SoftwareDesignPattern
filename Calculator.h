

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stdexcept>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include "Expression_Builder.h"
#include "Expression_Tree_Builder.h"
#include "Stack.h"
#include "Evaluate_Expression_Tree_Visitor.h"

class Calculator
{
public:
	// constructor for calculator 
	Calculator(void);

	// Destructor for calculator
	virtual ~Calculator(void);

	//evaluate expression
	int evaluateExpr(const std::string& infixExpression);

	//check the validity of expression
	bool is_valid_expression(const std::string& infixExpression);

	//check for the operator
	bool is_operator(std::string expr);

	//parse the expression
	bool parse_expr(const std::string& infixExpression, Expression_Builder& exp_builder);


};

#endif	