#include "Right_Parenthesis_Node.h"

//constructor for Right_Parenthesis_Node
Right_Parenthesis_Node::Right_Parenthesis_Node() {}

//destructor for Right_Parenthesis_Node
Right_Parenthesis_Node::~Right_Parenthesis_Node() {}

//evaluate expression
int Right_Parenthesis_Node::evaluate(void)
{
	return 1;
}

//expression
char Right_Parenthesis_Node::exp(void)
{
	return ')';
}

//accept visitor
void Right_Parenthesis_Node::accept(Expression_Node_Visitor& v) {}

//check precedence
int Right_Parenthesis_Node::precedence(void)
{
	return 0;
}
