#include "Modulus_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Modulus_Expression_Node
Modulus_Expression_Node::Modulus_Expression_Node(){}

Modulus_Expression_Node::Modulus_Expression_Node(Expression_Node* left_child, Expression_Node* right_child)
	:Binary_Expression_Node(left_child,right_child)
{}
//destructor for Modulus_Expression_Node
Modulus_Expression_Node::~Modulus_Expression_Node(){}

//check precedence
int Modulus_Expression_Node::precedence() {
	return 2;
}

//accept modulus node
void Modulus_Expression_Node::accept(Expression_Node_Visitor& v)
{
	v.Visit_Modulus_Node(*this);
}

//execute expressions
int Modulus_Expression_Node::executeExpression(int num1,int num2) {
	if (num2 == 0) {
		throw std::runtime_error("Number can't be divided by 0");
	}
	return num1 % num2;
}

//get expression
char Modulus_Expression_Node::exp(void)
{
	return '%';
}

//get left child
Expression_Node* Modulus_Expression_Node::getLeftChildOfTree() {
	return this->left_child;
}

//get right child
Expression_Node* Modulus_Expression_Node::getRightChildOfTree() {
	return this->right_child;

}
