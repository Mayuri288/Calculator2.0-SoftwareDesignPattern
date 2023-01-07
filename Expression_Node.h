#ifndef _EXPRESSION_NODE_H_
#define _EXPRESSION_NODE_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
class Expression_Node_Visitor;
class Expression_Node {
public:
	//constructor for Expression_Node
	Expression_Node(void);
	//destructor for Expression_Node
	virtual ~Expression_Node(void);
	//evaluate expression
	virtual int evaluate(void) = 0;
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v) = 0;
	//check precedence
	virtual int precedence(void) = 0;
	//get expression of operators
	virtual char exp(void) = 0;
};
#endif