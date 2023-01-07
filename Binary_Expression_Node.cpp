#include <iostream>
#include <stdexcept>
#include <algorithm>
#include<sstream>
#include<string>
#include "Binary_Expression_Node.h"

// constructor for Binary_Expression_Node
Binary_Expression_Node::Binary_Expression_Node():
	left_child(0),
	right_child(0)
{
}
// parametrized constructor for Binary_Expression_Node
Binary_Expression_Node::Binary_Expression_Node(Expression_Node* left_child, Expression_Node* right_child):
	left_child(left_child),
	right_child(right_child)
{
}
// destructor for Binary_Expression_Node
Binary_Expression_Node::~Binary_Expression_Node(){
	if (left_child != 0) {
		delete left_child;
	}
	
	if (right_child != 0) {
		delete right_child;
	}
		
}

//evaluate expressions
int Binary_Expression_Node::evaluate(void) {
	int left_child_ = left_child->evaluate();
	int right_child_ = right_child->evaluate();
	int result = this->executeExpression(left_child_, right_child_);
	return result;
}