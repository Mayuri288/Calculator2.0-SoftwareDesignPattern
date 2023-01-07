
#include "Division_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Division_Expression_Node
Division_Expression_Node::Division_Expression_Node(void) {}


//parametrized constructor for Division_Expression_Node
Division_Expression_Node::Division_Expression_Node(Expression_Node* left_child, Expression_Node* right_child)
	:Binary_Expression_Node(left_child, right_child){}

//destructor for Division_Expression_Node
Division_Expression_Node::~Division_Expression_Node(void) {}

//accept visitor
void Division_Expression_Node::accept(Expression_Node_Visitor& v) {
	v.Visit_Division_Node(*this);
}

//check precedence
int Division_Expression_Node::precedence(void) {
	return 2;
}


//execute operations
int Division_Expression_Node::executeExpression(int num1, int num2) {
	if (num2 == 0) {
		throw std::runtime_error("Number can't be divided by 0!");
	}
		
    return (num1 / num2);
}
//get expression of operator
char Division_Expression_Node::exp(void)
{
	return '/';
}
//get left child of tree
Expression_Node* Division_Expression_Node::getLeftChildOfTree() {
	return this->left_child;
}
//get right child of tree
Expression_Node* Division_Expression_Node::getRightChildOfTree () {
	return this->right_child;

}