
#include "Multiplication_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Multiplication_Expression_Node
Multiplication_Expression_Node::Multiplication_Expression_Node(void) {}

//parametrized constructor
Multiplication_Expression_Node::Multiplication_Expression_Node(Expression_Node* left_child, Expression_Node* right_child)
	:Binary_Expression_Node(left_child, right_child)
{}

//destructor for Multiplication_Expression_Node
Multiplication_Expression_Node::~Multiplication_Expression_Node(void) {}

//accept visitor
void Multiplication_Expression_Node::accept(Expression_Node_Visitor& v) {
	v.Visit_Multiplication_Node(*this);
}

//check precedence
int Multiplication_Expression_Node::precedence(void) {
	return 2;
}

//get expression
char Multiplication_Expression_Node::exp(void)
{
	return '*';
}
//execute expressions
int Multiplication_Expression_Node::executeExpression(int num1, int num2) {
	return (num1 * num2);
}

//get left child of tree
Expression_Node* Multiplication_Expression_Node::getLeftChildOfTree() {
	return this->left_child;
}

//get right chuild for tree
Expression_Node* Multiplication_Expression_Node::getRightChildOfTree() {
	return this->right_child;

}
