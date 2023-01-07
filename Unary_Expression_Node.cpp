#include "Unary_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Unary_Expression_Node
Unary_Expression_Node::Unary_Expression_Node(void)
	:child(0){}

//parametrized constructor for Unary_Expression_Node
Unary_Expression_Node::Unary_Expression_Node(Expression_Node* child)
	:child(child){}

//destructor for Unary_Expression_Node
Unary_Expression_Node::~Unary_Expression_Node(void)
{
	if (child != 0) {
		delete child;
	}
}

//evaluate expression

int Unary_Expression_Node::evaluate(void)
{
	if (this->child)
	{
		return -this->child->evaluate();
	}
	return 0;
}

//accept visitor
void Unary_Expression_Node::accept(Expression_Node_Visitor& v)
{
	v.Visit_Unary_Node(*this);
}

//get child of tree
Expression_Node* Unary_Expression_Node::getChildOfTree(void)
{
	return this->child;
}


//check precedence
int Unary_Expression_Node::precedence(void)
{
	return 3;
}

//expression
char Unary_Expression_Node::exp(void)
{
	return 'e';
}
