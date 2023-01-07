
#ifndef EXPRESSION_TREE_BUILDER_H_
#define EXPRESSION_TREE_BUILDER_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>

#include "Expression_Node.h"
#include "Expression_Builder.h"
#include "Number_Expression_Node.h"
#include "Unary_Expression_Node.h"
#include "Addition_Expression_Node.h"
#include "Subtraction_Expression_Node.h"
#include "Multiplication_Expression_Node.h"
#include "Division_Expression_Node.h"
#include "Modulus_Expression_Node.h"
#include "left_Parentheses_Node.h"
#include "Right_Parenthesis_Node.h"
#include "Evaluate_Expression_Factory.h"


class Expression_Tree_Builder : public Expression_Builder
{
public:
	//constructor for Expression_Tree_Builder
	Expression_Tree_Builder(void);

	//destructor for Expression_Tree_Builder
	virtual ~Expression_Tree_Builder(void);

	//build expression
	virtual void build_expression(void)
	{
		this->expression_tree = 0;
	}
	//build number node
	virtual void build_number_node(int n);

	//build unary node
	virtual void build_unary_node(void);

	//build addition node
	virtual void build_addition_node(void);

	//build subtraction node
	virtual void build_subtraction_node(void);

	//build multiplication node
	virtual void build_multiplication_node(void);

	//build division node
	virtual void build_division_node(void);

	//build modulus node
	virtual void build_modulus_node(void);

	//build left parenthesis node
	virtual void build_left_parenthesis(void);

	//build left parenthesis node
	virtual void build_right_parenthesis(void);

	//build empty unary node
	virtual void build_empty_unary_node(void);

	//build empty addition node
	virtual void build_empty_addition_node(void);

	//build empty subtraction node
	virtual void build_empty_subtraction_node(void);

	//build empty multiplication node
	virtual void build_empty_multiplication_node(void);

	//build empty division node
	virtual void build_empty_division_node(void);

	//build empty modulus node
	virtual void build_empty_mod_node(void);

	//build empty parenthesis node
	virtual void build_empty_parentheses_node(void);

	//build operator tree
	virtual void build_operator_tree(char token);

	//get expression
	virtual Expression_Node* getExpression(void);

private:

	Expression_Node* expression_tree;
	Evaluate_Expression_Factory ev_exp_factory;
	Expression_Node* empty_node;
};

#endif