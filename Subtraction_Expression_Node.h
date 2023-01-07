#ifndef _SUBTRACTION_EXPRESSION_NODE_
#define _SUBTRACTION_EXPRESSION_NODE_

#include "Binary_Expression_Node.h"
#include "Expression_Node.h"


class Subtraction_Expression_Node : public Binary_Expression_Node {
public:
	//constructor for Subtraction_Expression_Node
	Subtraction_Expression_Node(void);
	//parametrized constructor for Subtraction_Expression_Node
	Subtraction_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
	//destructor for Subtraction_Expression_Node
	virtual ~Subtraction_Expression_Node(void);
	//execute expressions
	virtual int executeExpression(int num1, int num2);
	//get precedence 
	virtual int precedence(void);
	//get left child
	virtual Expression_Node* getLeftChildOfTree();
	//get right child
	virtual Expression_Node* getRightChildOfTree();
	//accept visitor
	virtual void accept(Expression_Node_Visitor& v);
	//get expression
	virtual char exp(void);
};
#endif