#ifndef _MULTIPLICATION_EXPRESSION_NODE_H_
#define _MULTIPLICATION_EXPRESSION_NODE_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Binary_Expression_Node.h"

class Multiplication_Expression_Node :public Binary_Expression_Node 
{
public:
	//constructor for Multiplication_Expression_Node
	Multiplication_Expression_Node(void);
	//parametrized constructor for Multiplication_Expression_Node
	Multiplication_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
	//destructor for Multiplication_Expression_Node
	virtual ~Multiplication_Expression_Node(void);
	//check precedence
	virtual int precedence(void);
	//execute expressions
	virtual int executeExpression(int num1, int num2);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);
	//get left child
	virtual Expression_Node* getLeftChildOfTree();
	//get right child
	virtual Expression_Node* getRightChildOfTree();
	//get expression
	virtual char exp(void);
};
#endif // _MULTIPLICATION_EXPRESSION_NODE_H_