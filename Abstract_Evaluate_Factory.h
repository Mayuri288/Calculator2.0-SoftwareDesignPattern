
#ifndef ABSTRACT_NODE_FACTORY_H_
#define ABSTRACT_NODE_FACTORY_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Number_Expression_Node.h"
#include "Unary_Expression_Node.h"
#include "Addition_Expression_Node.h"
#include "Subtraction_Expression_Node.h"
#include "Multiplication_Expression_Node.h"
#include "Division_Expression_Node.h"
#include "Modulus_Expression_Node.h"
#include "left_Parentheses_Node.h"
#include "Right_Parenthesis_Node.h"


class Abstract_Evaluate_Factory
{
public:
	//constructor for Abstract_Evaluate_Factory
	Abstract_Evaluate_Factory(void);
	//Destructor for Abstract_Evaluate_Factory
	~Abstract_Evaluate_Factory(void);
	//create number node
	virtual Number_Expression_Node* create_number_node(int num) = 0;
	//create unary node
	virtual Unary_Expression_Node* create_unary_node(Expression_Node* num1) = 0;
	//create addition node
	virtual Addition_Expression_Node* create_addition_node(Expression_Node* num1, Expression_Node* num2) = 0;
	//create subtraction node
	virtual Subtraction_Expression_Node* create_subtraction_node(Expression_Node* num1, Expression_Node* num2) = 0;
	//create multiplication node
	virtual Multiplication_Expression_Node* create_multiplication_node(Expression_Node* num1, Expression_Node* num2) = 0;
	//create division node
	virtual Division_Expression_Node* create_division_node(Expression_Node* num1, Expression_Node* num2) = 0;
	//create modulus node
	virtual Modulus_Expression_Node* create_modulus_node(Expression_Node* num1, Expression_Node* num2) = 0;
	//create parenthesis node
	virtual left_Parenthesis_Node* create_parentheses_node(void) = 0;
	//create empty unary node
	virtual Unary_Expression_Node* create_empty_unary_node(void) = 0;
	//create empty addition node
	virtual Addition_Expression_Node* create_empty_addition_node(void) = 0;
	//create empty subtraction node
	virtual Subtraction_Expression_Node* create_empty_subtraction_node(void) = 0;
	//create empty multiplication node
	virtual Multiplication_Expression_Node* create_empty_multiplication_node(void) = 0;
	//create empty division node
	virtual Division_Expression_Node* create_empty_division_node(void) = 0;
	//create empty modulus node
	virtual Modulus_Expression_Node* create_empty_mod_node(void) = 0;
};

#endif		