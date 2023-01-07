
#include "Addition_Expression_Node.h"
#include "Expression_Node_Visitor.h"

//constructor for Addition_Expression_Node
Addition_Expression_Node::Addition_Expression_Node(void) {}

//parametrized constructor for Addition_Expression_Node
Addition_Expression_Node::Addition_Expression_Node(Expression_Node* left_child, Expression_Node* right_child)
	:Binary_Expression_Node(left_child, right_child){
}

//destructor for Addition_Expression_Node
Addition_Expression_Node::~Addition_Expression_Node(void){}

//accept visitor
void Addition_Expression_Node::accept(Expression_Node_Visitor& v) {
	v.Visit_Addition_Node(*this);
}
//check precedence
int Addition_Expression_Node::precedence(void) {
	return 1;
}

//get expression of operator
char Addition_Expression_Node::exp(void)
{
	return '+';
}

//execute expression
int Addition_Expression_Node::executeExpression(int num1, int num2) {
	return (num1 + num2);
}
//get left child
Expression_Node* Addition_Expression_Node::getLeftChildOfTree()
{
	return this->left_child;
}
//get right child
Expression_Node* Addition_Expression_Node::getRightChildOfTree()
{
	return this->right_child;
}
