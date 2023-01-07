#ifndef _LEFT_PARATHESIS_NODE_
#define _LEFT_PARATHESIS_NODE_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>

#include "Expression_Node.h"

// COMMENT: Per our discussion in class from Assignment 3, having
// the parenthesis as a node is not a good design. Please fix this
// problem in your design.
//Response: Tried to fix in validation part
class left_Parenthesis_Node :public Expression_Node {
public:
	//constructor for left parenthesis node
	left_Parenthesis_Node(void);
	//destructor for left parenthesis node
	virtual ~left_Parenthesis_Node(void);
	//evaluate expression
	virtual int evaluate(void);
	//check precedence
	virtual int precedence(void);
	//get expression of operator
	virtual char exp(void);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);

};
#endif
