
#include "Subtraction_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Subtraction_Expression_Node
Subtraction_Expression_Node::Subtraction_Expression_Node() {}

//parametrized constructor for Subtraction_Expression_Node
Subtraction_Expression_Node::Subtraction_Expression_Node(Expression_Node* left_child, Expression_Node* right_child)
	:Binary_Expression_Node(left_child, right_child)
{}

//destructor for Subtraction_Expression_Node
Subtraction_Expression_Node::~Subtraction_Expression_Node(void) {}

//accept visitor 
void Subtraction_Expression_Node::accept(Expression_Node_Visitor& v) {
	v.Visit_Subtraction_Node(*this);
}

//check precedence
int Subtraction_Expression_Node::precedence(void) {
	return 1;
}

//get left child of tree
Expression_Node* Subtraction_Expression_Node::getLeftChildOfTree() {
	return this->left_child;
}

//get right child of tree
Expression_Node* Subtraction_Expression_Node::getRightChildOfTree() {
	return this->right_child;

}

//execute expression
int Subtraction_Expression_Node::executeExpression(int num1, int num2)
{
	return (num1 - num2);
}

//expression
char Subtraction_Expression_Node::exp(void)
{
	return '-';
}
