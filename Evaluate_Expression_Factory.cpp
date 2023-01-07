
#include"Evaluate_Expression_Factory.h"

//constructor for Evaluate_Expression_Factory
Evaluate_Expression_Factory::Evaluate_Expression_Factory(){}

//destructor for Evaluate_Expression_Factory
Evaluate_Expression_Factory::~Evaluate_Expression_Factory(void){}

//create number node
Number_Expression_Node* Evaluate_Expression_Factory::create_number_node(int num)
{
	return new Number_Expression_Node(num);
}

//create unary node
Unary_Expression_Node* Evaluate_Expression_Factory::create_unary_node(Expression_Node* num1)
{
	return new Unary_Expression_Node(num1);
}

////create addition node
Addition_Expression_Node* Evaluate_Expression_Factory::create_addition_node(Expression_Node* num1, Expression_Node* num2)
{
	return new Addition_Expression_Node(num1, num2);
}

//create subtraction node
Subtraction_Expression_Node* Evaluate_Expression_Factory::create_subtraction_node(Expression_Node* num1, Expression_Node* num2)
{
	return new Subtraction_Expression_Node(num1, num2);
}

//create multiplication node
Multiplication_Expression_Node* Evaluate_Expression_Factory::create_multiplication_node(Expression_Node* num1, Expression_Node* num2)
{
	return new Multiplication_Expression_Node(num1, num2);
}

//create division node
Division_Expression_Node* Evaluate_Expression_Factory::create_division_node(Expression_Node* num1, Expression_Node* num2)
{
	return new Division_Expression_Node(num1, num2);
}

//create modulus node
Modulus_Expression_Node* Evaluate_Expression_Factory::create_modulus_node(Expression_Node* num1, Expression_Node* num2)
{
	return new Modulus_Expression_Node(num1, num2);
}

//create parentheses node
left_Parenthesis_Node* Evaluate_Expression_Factory::create_parentheses_node(void)
{
	return new left_Parenthesis_Node();
}

//create empty unary node
Unary_Expression_Node* Evaluate_Expression_Factory::create_empty_unary_node(void)
{
	return new Unary_Expression_Node();
}

//create empty addition node
Addition_Expression_Node* Evaluate_Expression_Factory::create_empty_addition_node(void)
{
	return new Addition_Expression_Node();
}


//create empty subtraction node
Subtraction_Expression_Node* Evaluate_Expression_Factory::create_empty_subtraction_node(void)
{
	return new Subtraction_Expression_Node();
}


//create empty multiplication node
Multiplication_Expression_Node* Evaluate_Expression_Factory::create_empty_multiplication_node(void)
{
	return new Multiplication_Expression_Node();
}


//create empty division node
Division_Expression_Node* Evaluate_Expression_Factory::create_empty_division_node(void)
{
	return new Division_Expression_Node();
}


//create empty modulus node
Modulus_Expression_Node* Evaluate_Expression_Factory::create_empty_mod_node(void)
{
	return new Modulus_Expression_Node();
}
