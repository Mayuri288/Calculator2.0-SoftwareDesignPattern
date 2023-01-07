#include "Expression_Node.h"
#include "Binary_Expression_Node.h"
#include "Addition_Expression_Node.h"
#include "Division_Expression_Node.h"
#include "Modulus_Expression_Node.h"
#include "Multiplication_Expression_Node.h"
#include "Number_Expression_Node.h"
#include "Subtraction_Expression_Node.h"
#include "Unary_Expression_Node.h"
#include "Right_Parenthesis_Node.h"
#include "left_Parentheses_Node.h"
#include "Evaluate_Expression_Tree_Visitor.h"
#include "Expression_Node_Visitor.h"
#include "Calculator.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include<sstream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
	Calculator calculate;
	std::string expression;
	bool check = false;
	bool keep_going = true;
	int value;
	

	while (keep_going) {
		std::cout << "Enter Expression:" << std::endl;
		std::getline(std::cin, expression,'\n');
		if (expression != "QUIT") {
			std::string exp="";
			size_t i = 0;
			while (i < expression.size()) {
				if (isalpha(expression[i])) {
					std::cout << "Enter the value of:" << expression[i] << std::endl;
					std::cin >> value;
					//ignoring new line stored in buffer
					cin.ignore();
					//convert value to string
					exp = exp + std::to_string(value);
				}
				else
					exp = exp + expression[i];
					
				i++;
			}
			expression = exp;
		}

		else if (expression == "QUIT") {
			keep_going = false;
			break;
		}
		

		try
		{
			//Evaluate expression and get result
			int result = calculate.evaluateExpr(expression);
			std::cout << "Evaluation result is: "<< result << std::endl;

		}
		//Catching invalid expression, division by zero, modulus by zero errors
		catch (std::exception& exp)
		{
			std::cout << exp.what() << std::endl;
		}

	}
	return 0;
}
