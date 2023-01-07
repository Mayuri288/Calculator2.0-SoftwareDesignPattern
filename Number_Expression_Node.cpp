
#include "Number_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Number_Expression_Node
Number_Expression_Node::Number_Expression_Node(void) {}

//parametrized constructor for Number_Expression_Node
Number_Expression_Node::Number_Expression_Node(int number)
	:number(number){}

//destructor for Number_Expression_Node
Number_Expression_Node::~Number_Expression_Node(void) {}

//evaluate expression
int Number_Expression_Node::evaluate()
{
	return number;
}

//accept visitor
void Number_Expression_Node::accept(Expression_Node_Visitor& v) {
	v.Visit_Number_Node(*this);
}

//check precedence
int Number_Expression_Node::precedence(void) {
	return 0;
}

//get expression
int Number_Expression_Node::getExpression(void)
{
	return number;
}

//expression
char Number_Expression_Node::exp(void)
{
	return 'n';
}
