

#include "Expression_Tree_Builder.h"

// COMMENTS Add more comments, and try to remove duplicate code by using
// helper methods/functions.
//Response : Added

Expression_Tree_Builder::Expression_Tree_Builder() {}

Expression_Tree_Builder::~Expression_Tree_Builder() {}

void Expression_Tree_Builder::build_operator_tree(char token)
{
	//multiplication node with first two numbers on stack
	if (token == '*') {
		Expression_Node* num2 = expression_node.top();
		expression_node.pop();
		Expression_Node* num1 = expression_node.top();
		expression_node.pop();
		Expression_Node* tree = ev_exp_factory.create_multiplication_node(num1, num2);
		expression_node.push(tree);
	}
	//division node with first two numbers on stack
	else if (token == '/')
	{
		Expression_Node* num2 = expression_node.top();
		expression_node.pop();
		Expression_Node* num1 = expression_node.top();
		expression_node.pop();
		Expression_Node* tree = ev_exp_factory.create_division_node(num1, num2);
		expression_node.push(tree);
	}
	//addition node with first two numbers on stack
	else if (token == '+')
	{
		Expression_Node* num2 = expression_node.top();
		expression_node.pop();
		Expression_Node* num1 = expression_node.top();
		expression_node.pop();
		Expression_Node* tree = ev_exp_factory.create_addition_node(num1, num2);
		expression_node.push(tree);
	}
	//subtraction node with first two numbers on stack
	else if (token == '-')
	{
		Expression_Node* num2 = expression_node.top();
		expression_node.pop();
		Expression_Node* num1 = expression_node.top();
		expression_node.pop();
		Expression_Node* tree = ev_exp_factory.create_subtraction_node(num1, num2);
		expression_node.push(tree);
	}
	//modulus node with first two numbers on stack
	else if (token == '%')
	{
		Expression_Node* num2 = expression_node.top();
		expression_node.pop();
		Expression_Node* num1 = expression_node.top();
		expression_node.pop();
		Expression_Node* tree = ev_exp_factory.create_modulus_node(num1, num2);
		expression_node.push(tree);
	}
	//unary node with first two numbers on stack
	else if (token == 'e')
	{
		Expression_Node* num1 = expression_node.top();
		Expression_Node* tree = ev_exp_factory.create_unary_node(num1);
		expression_node.pop();
		expression_node.push(tree);
	}
}

//build number node
void Expression_Tree_Builder::build_number_node(int num)
{
	Expression_Node* tree = ev_exp_factory.create_number_node(num);
	expression_node.push(tree);
}
//build unary node
void Expression_Tree_Builder::build_unary_node(void)
{
	build_empty_unary_node();
	if (!(operator_node.is_empty()))
	{
		while (operator_node.top()->exp() == 'e')
		{

			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
		}
	}
	operator_node.push(empty_node);
}

//build addition node
void Expression_Tree_Builder::build_addition_node(void)
{
	build_empty_addition_node();

	if (operator_node.is_empty())
	{
		operator_node.push(empty_node);
	}
	else if (operator_node.top()->exp() == '(')
	{
		operator_node.push(empty_node);
	}
	else if (operator_node.top()->precedence() >= empty_node->precedence())
	{
		while (operator_node.top()->precedence() >= empty_node->precedence())
		{
			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
			if ((operator_node.is_empty()) || (operator_node.top()->exp() == '('))
			{
				operator_node.push(empty_node);
				break;
			}
		}
		if (operator_node.top()->precedence() < empty_node->precedence())
		{
			operator_node.push(empty_node);
		}
	}
	else if (operator_node.top()->precedence() < empty_node->precedence())
	{
		operator_node.push(empty_node);
	}
}


//build subtraction node
void Expression_Tree_Builder::build_subtraction_node(void)
{
	build_empty_subtraction_node();

	if (operator_node.is_empty())
	{
		operator_node.push(empty_node);
	}
	else if (operator_node.top()->exp() == '(')
	{
		operator_node.push(empty_node);
	}

	else if (operator_node.top()->precedence() >= empty_node->precedence())
	{
		while (operator_node.top()->precedence() >= empty_node->precedence())
		{
			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
			if ((operator_node.is_empty()) || (operator_node.top()->exp() == '('))
			{
				operator_node.push(empty_node);
				break;
			}
		}
		if (operator_node.top()->precedence() < empty_node->precedence())
		{
			operator_node.push(empty_node);
		}
	}

	else if (operator_node.top()->precedence() < empty_node->precedence())
	{
		operator_node.push(empty_node);
	}
}
//build multiplication node
void Expression_Tree_Builder::build_multiplication_node(void)
{	//build empty node first
	build_empty_multiplication_node();

	if (operator_node.is_empty())
	{
		operator_node.push(empty_node);
	}
	//check for '('
	else if (operator_node.top()->exp() == '(')
	{
		operator_node.push(empty_node);
	}
	//check precedence of expression
	else if (operator_node.top()->precedence() >= empty_node->precedence())
	{
		while (operator_node.top()->precedence() >= empty_node->precedence())
		{
			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
			if ((operator_node.is_empty()) || (operator_node.top()->exp() == '('))
			{
				operator_node.push(empty_node);
				break;
			}
		}
		if (operator_node.top()->precedence() < empty_node->precedence())
		{
			operator_node.push(empty_node);
		}
	}
	else if (operator_node.top()->precedence() < empty_node->precedence())
	{
		operator_node.push(empty_node);
	}
}

//build division node
void Expression_Tree_Builder::build_division_node(void)
{
	//build empty node first
	build_empty_division_node();

	if (operator_node.is_empty())
	{
		operator_node.push(empty_node);
	}
	else if (operator_node.top()->exp() == '(')
	{
		operator_node.push(empty_node);
	}
	//check for precedence
	else if (operator_node.top()->precedence() >= empty_node->precedence())
	{
		while (operator_node.top()->precedence() >= empty_node->precedence())
		{
			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
			if ((operator_node.is_empty()) || (operator_node.top()->exp() == '('))
			{
				operator_node.push(empty_node);
				break;
			}
		}
		if (operator_node.top()->precedence() < empty_node->precedence())
		{
			operator_node.push(empty_node);
		}
	}

	else if (operator_node.top()->precedence() < empty_node->precedence())
	{
		operator_node.push(empty_node);
	}
}

//build modulus node
void Expression_Tree_Builder::build_modulus_node(void)
{
	//build empty node first
	build_empty_mod_node();

	if (operator_node.is_empty())
	{
		operator_node.push(empty_node);
	}
	else if (operator_node.top()->exp() == '(')
	{
		operator_node.push(empty_node);
	}
	//check for precedence
	else if (operator_node.top()->precedence() >= empty_node->precedence())
	{
		while (operator_node.top()->precedence() >= empty_node->precedence())
		{
			build_operator_tree(operator_node.top()->exp());
			delete operator_node.top();
			operator_node.pop();
			if ((operator_node.is_empty()) || (operator_node.top()->exp() == '('))
			{
				operator_node.push(empty_node);
				break;
			}
		}
		if (operator_node.top()->precedence() < empty_node->precedence())
		{
			operator_node.push(empty_node);
		}
	}

	else if (operator_node.top()->precedence() < empty_node->precedence())
	{
		operator_node.push(empty_node);
	}
}

//build left parentheses node
void Expression_Tree_Builder::build_left_parenthesis(void)
{
	build_empty_parentheses_node();
	operator_node.push(empty_node);
}

//build right parentheses node
void Expression_Tree_Builder::build_right_parenthesis(void)
{
	while (!(operator_node.top()->exp() == '('))
	{
		build_operator_tree(operator_node.top()->exp());
		delete operator_node.top();
		operator_node.pop();
		if (operator_node.is_empty()) break;
	}
	if (!(operator_node.is_empty()))
	{
		delete operator_node.top();
		operator_node.pop();
	}
}

//build empty unary node
void Expression_Tree_Builder::build_empty_unary_node(void)
{
	empty_node = ev_exp_factory.create_empty_unary_node();
}

//build empty addition node
void Expression_Tree_Builder::build_empty_addition_node(void)
{
	empty_node = ev_exp_factory.create_empty_addition_node();
}

//build empty suntraction node
void Expression_Tree_Builder::build_empty_subtraction_node(void)
{
	empty_node = ev_exp_factory.create_empty_subtraction_node();
}

//build empty multiplication node
void Expression_Tree_Builder::build_empty_multiplication_node(void)
{
	empty_node = ev_exp_factory.create_empty_multiplication_node();
}

//build empty division node
void Expression_Tree_Builder::build_empty_division_node(void)
{
	empty_node = ev_exp_factory.create_empty_division_node();
}

//build empty modulus node
void Expression_Tree_Builder::build_empty_mod_node(void)
{
	empty_node = ev_exp_factory.create_empty_mod_node();
}

//build empty parentheses node
void Expression_Tree_Builder::build_empty_parentheses_node(void)
{
	empty_node = ev_exp_factory.create_parentheses_node();
}

//get expression of nodes
Expression_Node* Expression_Tree_Builder::getExpression(void)
{
	while (!(operator_node.is_empty()))
	{
		build_operator_tree(operator_node.top()->exp());
		delete operator_node.top();
		operator_node.pop();
	}
	if (!(operator_node.is_empty()))
	{
		for (size_t i = 0; i < operator_node.size(); i++)
		{
			delete operator_node.top();
			operator_node.pop();
		}
	}

	this->expression_tree = expression_node.top();
	return this->expression_tree;
}
