#ifndef _UNARY_EXPRESSION_NODE_
#define _UNARY_EXPRESSION_NODE_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"

class Unary_Expression_Node:public Expression_Node{
public:
	//constructor for Unary_Expression_Node
	Unary_Expression_Node(void);

	//parametrized constructor for Unary_Expression_Node
	Unary_Expression_Node(Expression_Node* childOfTree);

	//destructor for Unary_Expression_Node
	virtual ~Unary_Expression_Node(void);

	//evaluate expression
	virtual int evaluate(void);

	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);

	//get child of tree
	virtual Expression_Node* getChildOfTree(void);

	//get precedence
	virtual int precedence(void);

	//get expression
	virtual char exp(void);


private:
	Expression_Node* child;
};

#endif // !_UNARY_EXPRESSION_NODE_