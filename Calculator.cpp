
#include "Calculator.h"

Calculator::Calculator(){}

Calculator::~Calculator(){}

//
//evaluate_expr
//
int Calculator::evaluateExpr(const std::string& infixExpression)
{
	if (!(is_valid_expression(infixExpression)))
	{
		throw std::runtime_error("Invalid expression entered!");
	}
	Expression_Tree_Builder exp_tree_builder;
	if (!(this->parse_expr(infixExpression, exp_tree_builder)))
		return false;
	//Getting the expression tree
	Expression_Node* expr_node = exp_tree_builder.getExpression();

	//Visitor for postfix traversal
	Evaluate_Expression_Tree_Visitor eval_expr;

	if (0 == expr_node)
		return false;
	try
	{
		expr_node->accept(eval_expr);
	}
	catch (std::exception)
	{
		if (expr_node != 0)
			delete expr_node;
		throw;
	}

	int result = eval_expr.result();
	delete expr_node;

	return result;

}

//
//is_operator
//
bool Calculator::is_operator(std::string expr)
{
	if (expr == "+") {
		return true;
	}
	else if (expr == "-") {
		return true;
	}
	else if (expr == "*") {
		return true;
	}
	else if (expr == "/") {
		return true;
	}
	else if (expr == "%") {
		return true;
	}
	else return false;
}
bool Calculator::parse_expr(const std::string& infixExpression, Expression_Builder& exp_builder)
{
	std::istringstream inputExpression(infixExpression);
	std::string expression;
	int digits = 0;
	int operators = 0;
	exp_builder.build_expression();

	while (inputExpression >> expression)
	{
		if (expression == "(")
		{
			exp_builder.build_left_parenthesis();
		}
		else if ((isdigit(expression[0])) || ((expression.size() >= 2) && (atoi(expression.c_str()))))
		{
			digits++;
			int val = atoi(expression.c_str());
			exp_builder.build_number_node(val);
		}
		else if (is_operator(expression))
		{
			operators++;
			//Condition to check for unary operator
			if (operators > digits)
			{
				exp_builder.build_unary_node();
				operators--;
				continue;
			}

			//Building the respective operator tree
			if (expression == "+") exp_builder.build_addition_node();
			else if (expression == "-") exp_builder.build_subtraction_node();
			else if (expression == "*") exp_builder.build_multiplication_node();
			else if (expression == "/") exp_builder.build_division_node();
			else if (expression == "%") exp_builder.build_modulus_node();
		}
		else if (expression == ")")
		{
			//Building expression in parentheses
			exp_builder.build_right_parenthesis();
		}
		else
		{
			//If something other than a number is entered
			return false;
		}
	}
	return true;
}


bool Calculator::is_valid_expression(const std::string& infixExpression)
{
	if (infixExpression[0] == ' ')
	{
		return false;
	}
	//checking for white spaces in infixExpression expression 
	int last = infixExpression.size() - 1;
	if (infixExpression[last] == ' ')
	{
		return false;
	}
	//Check for unary expression
	int unary_minus = 0;
	if (infixExpression[0] == '-')
	{
		//check for the digits
		int index1 = infixExpression.find_first_of("0123456789");
		if ((index1 == 1) || (index1 == 2) || (index1 == 3))
			unary_minus = 1;

		std::istringstream inputExpression(infixExpression);
		std::string expression;
		int countValidity = 1;
		int checkCount = 0;
		while (inputExpression >> expression)
		{
			checkCount++;
			if ((checkCount == 1) && (expression == "-") && (unary_minus == 1))
			{
				countValidity = 1;
			}
			else if (isdigit(expression[0]))
				countValidity--;
			else if ((expression.size() >= 2) && (atoi(expression.c_str())))
				countValidity--;
			else if ((expression == "+") || (expression == "-") || (expression == "*") || (expression == "/") || (expression == "%"))
				countValidity++;
		}
		if (countValidity < 0)
		{
			return false;
		}
	}
	//check validity of expression
	int countValidityOfExpression = 1;
	int binary_operators = 0;
	int unary_operator = 0;
	for (size_t i = 0; i < infixExpression.size(); i++)
	{
		//is operator?
		if ((infixExpression[i] == '+') || (infixExpression[i] == '-') ||
			(infixExpression[i] == '*') || (infixExpression[i] == '/') ||
			(infixExpression[i] == '%'))
		{
			countValidityOfExpression++;
			binary_operators++;
		}
		if (infixExpression[i] == '-')
		{
			int minus_index = infixExpression.find_first_of("0123456789", i + 1);
			if (minus_index == i + 1)
			{
				countValidityOfExpression--;
				binary_operators--;
			}
			//is minus a unary expression?
			if (((minus_index == i + 2) && (i == 0)) || ((minus_index == i + 2) && ((infixExpression[i - 2] == '(') ||
				(infixExpression[i - 2] == '+') || (infixExpression[i - 2] == '-') || (infixExpression[i - 2] == '*') ||
				(infixExpression[i - 2] == '/') || (infixExpression[i - 2] == '%'))))
			{
				countValidityOfExpression--;
				binary_operators--;
				unary_operator = 1;
			}
			//Checking if the minus is unary of negation
			if (((minus_index == i + 3) && (i == 0)) || ((minus_index == i + 3) &&
				((infixExpression[i - 2] == '(') || (infixExpression[i - 2] == '+') ||
					(infixExpression[i - 2] == '-') || (infixExpression[i - 2] == '*') ||
					(infixExpression[i - 2] == '/') || (infixExpression[i - 2] == '%'))))
			{
				countValidityOfExpression--;
				binary_operators--;
				unary_operator = 1;
			}
			//Checking for unary parenthesized expression
			if (((infixExpression[i + 2] == '(') && (i == 0)) ||
				((infixExpression[i + 2] == '(') && ((infixExpression[i - 2] == '(') ||
					(infixExpression[i - 2] == '+') || (infixExpression[i - 2] == '-') ||
					(infixExpression[i - 2] == '*') || (infixExpression[i - 2] == '/') ||
					(infixExpression[i - 2] == '%'))))
			{
				countValidityOfExpression--;
				binary_operators--;
				unary_operator = 1;
			}
		}
	}
	//If there are no binary operators then throw exception
	if (binary_operators <= 0)
	{
		return false;
	}
	//Checking if operands and operators are balanced
	std::istringstream input(infixExpression);
	std::string token;
	while (input >> token)
	{
		if (isdigit(token[0]))
			countValidityOfExpression--;
		else if ((token.size() >= 2) && (atoi(token.c_str())))
			countValidityOfExpression--;
	}
	//If the expression is unbalanced
	if (countValidityOfExpression != 0)
	{
		return false;
	}

	int whiteSpaceIndex = infixExpression.find(' ');
	if (whiteSpaceIndex == 0)
	{
		return false;
	}
	for (size_t i = 0; i < infixExpression.size(); i++)
	{
		//check consecutive white spaces
		int cons_index = infixExpression.find(' ', whiteSpaceIndex + 1);
		if (cons_index == whiteSpaceIndex + 1)
		{
			return false;
		}
		whiteSpaceIndex = cons_index;
	}
	//check for operators along with numbers
	if ((infixExpression.find_first_of("+-*/%")) == std::string::npos)
	{
		return false;
	}

	if (infixExpression.find_first_of("0123456789") == std::string::npos)
	{
		return false;
	}

	//Checking if postfix expression is entered
	std::istringstream inputExp(infixExpression);
	std::string exp;
	int countValidExpression = 1;
	while (inputExp >> exp)
	{
		if ((isdigit(exp[0])) || (atoi(exp.c_str())))
		{
			countValidExpression--;
			if (countValidExpression < 0)
			{
				return false;
			}
		}
		else if ((exp[0] == '+') || (exp[0] == '-') || (exp[0] == '*') || (exp[0] == '/') || (exp[0] == '%'))
			countValidExpression++;
	}
	//Checking for balanced parentheses
	int equal_parenthesis = 0;
	int digit_position = 0;
	int parenthesis_position = 0;
	for (size_t i = 0; i < infixExpression.size(); i++)
	{
		if (infixExpression[i] == '(')
		{
			equal_parenthesis++;
			if (infixExpression[i + 1] != ' ')
				return false;
			if (i != 0)
			{
				if (infixExpression[i - 1] != ' ')
					return false;
			}
			//digits between parenthesis
			digit_position = infixExpression.find_first_of("0123456789", i + 1);
			parenthesis_position = infixExpression.find_first_of(')', i + 1);
			if ((digit_position >= parenthesis_position) || (digit_position == std::string::npos))
				return false;
		}
		if (infixExpression[i] == ')')
		{
			equal_parenthesis--;

			if (infixExpression[i - 1] != ' ')
				return false;
			if (i != (infixExpression.size() - 1))
			{
				if (infixExpression[i + 1] != ' ')
					return false;
			}
		}
		if (equal_parenthesis < 0)
			return false;
	}
	if (equal_parenthesis != 0)
		return false;


	return true;
}
