#ifndef _DIVISION_EXPRESSION_NODE_H_
#define _DIVISION_EXPRESSION_NODE_H_

#include<stdexcept>
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Binary_Expression_Node.h"

class Division_Expression_Node:public Binary_Expression_Node {
public:
	//constructor for Division_Expression_Node
	Division_Expression_Node(void);
	// parametrized constructor for Division_Expression_Node
	Division_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
	//destructor for Division_Expression_Node
	virtual ~Division_Expression_Node(void);
	//execute expressions
	virtual int executeExpression(int num1, int num2);
	//check precedence
	virtual int precedence(void);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);
	//left child of tree
	virtual Expression_Node* getLeftChildOfTree();
	//right child of tree
	virtual Expression_Node* getRightChildOfTree();
	//get expression of operator
	virtual char exp(void);
};
#endif