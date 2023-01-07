#ifndef EXPRESSION_NODE_VISITOR_H_
#define EXPRESSION_NODE_VISITOR_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Addition_Expression_Node.h"
#include "Subtraction_Expression_Node.h"
#include "Division_Expression_Node.h"
#include "Multiplication_Expression_Node.h"
#include "Number_Expression_Node.h"
#include "Modulus_Expression_Node.h"
#include "Unary_Expression_Node.h"
#include "left_Parentheses_Node.h"
#include "Right_Parenthesis_Node.h"

class Expression_Node_Visitor {
public:
	//constructor for Expression_Node_Visitor
	Expression_Node_Visitor(void);
	//destructor for Expression_Node_Visitor
	virtual ~Expression_Node_Visitor(void);
	// visit addition node
	virtual void Visit_Addition_Node( Addition_Expression_Node& node)=0;
	// visit subtraction node
	virtual void Visit_Subtraction_Node( Subtraction_Expression_Node& node)=0;
	// visit multiplication node
	virtual void Visit_Multiplication_Node( Multiplication_Expression_Node& node)=0;
	// visit division node
	virtual void Visit_Division_Node( Division_Expression_Node& node)=0;
	// visit modulus node
	virtual void Visit_Modulus_Node( Modulus_Expression_Node& node)=0;
	// visit number node
	virtual void Visit_Number_Node( Number_Expression_Node& node)=0;
	// visit unary node
	virtual void Visit_Unary_Node( Unary_Expression_Node& node)=0;
}; 
#endif