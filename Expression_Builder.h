#ifndef _EXPRESSION_BUILDER_H_
#define _EXPRESSION_BUILDER_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Stack.h"
class Expression_Builder {
public:
	//constructor for Expression_Builder
	Expression_Builder(void);

	//destructor for Expression_Builder
	virtual ~Expression_Builder(void);

	//build number node
	virtual void build_number_node(int n) = 0;

	//build addition node
	virtual void build_addition_node(void) = 0;

	//build subtraction node
	virtual void build_subtraction_node(void) = 0;

	//build division node
	virtual void build_division_node(void) = 0;

	//build multiplication node
	virtual void build_multiplication_node(void) = 0;

	//build modulus node
	virtual void build_modulus_node(void) = 0;

	//build unary node
	virtual void build_unary_node(void) = 0;

	//build left parentheses
	virtual void build_left_parenthesis(void) = 0;

	//build right parentheses
	virtual void build_right_parenthesis(void) = 0;

	//build expression
	virtual void build_expression(void) = 0;

	//build empty addition node
	virtual void build_empty_addition_node(void) = 0;

	//build empty subtraction node
	virtual void build_empty_subtraction_node(void) = 0;

	//build empty multiplication node
	virtual void build_empty_multiplication_node(void) = 0;

	//build empty division node
	virtual void build_empty_division_node(void) = 0;

	//build empty mod node
	virtual void build_empty_mod_node(void) = 0;

	//build empty unary node
	virtual void build_empty_unary_node(void) = 0;

	//build empty parentheses node
	virtual void build_empty_parentheses_node(void) = 0;

	//build operator tree
	virtual void build_operator_tree(char token) = 0;

	//get expression
	virtual Expression_Node* getExpression(void) = 0;

protected:

	Stack<Expression_Node*> expression_node;
	Stack<Expression_Node*> operator_node;



};
#endif
