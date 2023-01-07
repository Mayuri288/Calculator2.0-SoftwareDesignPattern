#ifndef _RIGHT_PARATHESIS_NODE_
#define _RIGHT_PARATHESIS_NODE_


#include "Expression_Node.h"

// COMMENT: Per our discussion in class from Assignment 3, having
// the parenthesis as a node is not a good design. Please fix this
// problem in your design.

//Response: Tried to fix in validation part

class Right_Parenthesis_Node : public Expression_Node {
public:
	//constructor for Right_Parenthesis_Node
	Right_Parenthesis_Node(void);
	//destructor for Right_Parenthesis_Node
	virtual ~Right_Parenthesis_Node(void);
	//evaluate expression
	virtual int evaluate(void);
	//precedence
	virtual int precedence(void);
	//get expression
	virtual char exp(void);
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);

};
#endif
