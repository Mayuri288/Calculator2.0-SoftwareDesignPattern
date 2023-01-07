#ifndef _ADDITION_EXPRESSION_NODE_H_
#define _ADDITION_EXPRESSION_NODE_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Binary_Expression_Node.h"

class Addition_Expression_Node :public Binary_Expression_Node {
public:
	//constructor for Addition_Expression_Node
	Addition_Expression_Node(void);
	//parametrized constructor for Addition_Expression_Node
	Addition_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
	//destructor for Addition_Expression_Node
	virtual ~Addition_Expression_Node(void);
	//execute expression
	virtual int executeExpression(int num1, int num2);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);
	//check precedence
	virtual int precedence(void);
	//get left child of tree
	virtual Expression_Node* getLeftChildOfTree();
	//get right child of tree
	virtual Expression_Node* getRightChildOfTree();
	//get expression
	virtual char exp(void);
};
#endif
