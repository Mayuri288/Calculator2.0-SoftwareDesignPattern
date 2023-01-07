#include "left_Parentheses_Node.h"

left_Parenthesis_Node::left_Parenthesis_Node(){}

left_Parenthesis_Node::~left_Parenthesis_Node(){}

int left_Parenthesis_Node::evaluate(void)
{
	return 1;
}
char left_Parenthesis_Node::exp(void)
{
	return '(';
}

void left_Parenthesis_Node::accept(Expression_Node_Visitor& v){
}

int left_Parenthesis_Node::precedence(void)
{
	return 0;
}