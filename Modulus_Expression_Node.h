#ifndef _MODULUS_EXPRESSION_NODE_H_
#define _MODULUS_EXPRESSION_NODE_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Binary_Expression_Node.h"
#include "Expression_Node.h"
class Modulus_Expression_Node : public Binary_Expression_Node {
public:
	//constructor for Modulus_Expression_Node
	Modulus_Expression_Node(void);
	//parametrized constructor for Modulus_Expression_Node
	Modulus_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
	//destructor for Modulus_Expression_Node
	virtual ~Modulus_Expression_Node(void);
	//execute expressions
	virtual int executeExpression(int num1, int num2);
	//check precedence
	virtual int precedence(void);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);
	//get left child
	virtual Expression_Node* getLeftChildOfTree();
	//get right child
	virtual Expression_Node* getRightChildOfTree();
	//get expression
	virtual char exp(void);
};
#endif