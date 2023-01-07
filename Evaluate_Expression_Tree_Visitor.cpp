#include "Evaluate_Expression_Tree_Visitor.h"

//constructor for Evaluate_Expression_Tree_Visitor
Evaluate_Expression_Tree_Visitor::Evaluate_Expression_Tree_Visitor(){}

//destructor for Evaluate_Expression_Tree_Visitor
Evaluate_Expression_Tree_Visitor::~Evaluate_Expression_Tree_Visitor(){}

//visit addition node
void Evaluate_Expression_Tree_Visitor::Visit_Addition_Node(Addition_Expression_Node& node)
{
	//accept left child of tree
	Evaluate_Expression_Tree_Visitor left_node;
	node.getLeftChildOfTree()->accept(left_node);
	int leftNode_result = left_node.result();

	//accept right child of tree
	Evaluate_Expression_Tree_Visitor right_node;
	node.getRightChildOfTree()->accept(right_node);
	int rightNode_result = right_node.result();

	//get results
	result_ = leftNode_result + rightNode_result;
}

//visit subtraction node
void Evaluate_Expression_Tree_Visitor::Visit_Subtraction_Node(Subtraction_Expression_Node& node)
{
	//accept left child of tree
	Evaluate_Expression_Tree_Visitor left_node;
	node.getLeftChildOfTree()->accept(left_node);
	int leftNode_result = left_node.result();

	//accept right child of tree
	Evaluate_Expression_Tree_Visitor right_node;
	node.getRightChildOfTree()->accept(right_node);
	int rightNode_result = right_node.result();

	//get results
	result_ = leftNode_result - rightNode_result;
}

//visit multiplication node
void Evaluate_Expression_Tree_Visitor::Visit_Multiplication_Node(Multiplication_Expression_Node& node)
{
	//accept left child of tree
	Evaluate_Expression_Tree_Visitor left_node;
	node.getLeftChildOfTree()->accept(left_node);
	int leftNode_result = left_node.result();

	//accept right child of tree
	Evaluate_Expression_Tree_Visitor right_node;
	node.getRightChildOfTree()->accept(right_node);
	int rightNode_result = right_node.result();
	//get results
	result_ = leftNode_result * rightNode_result;
}

//visit division node
void Evaluate_Expression_Tree_Visitor::Visit_Division_Node( Division_Expression_Node& node)
{
	//accept left child of tree
	Evaluate_Expression_Tree_Visitor left_node;
	node.getLeftChildOfTree()->accept(left_node);
	int leftNode_result = left_node.result();

	//accept right child of tree
	Evaluate_Expression_Tree_Visitor right_node;
	node.getRightChildOfTree()->accept(right_node);
	int rightNode_result = right_node.result();
	if (rightNode_result == 0) {
		throw std::runtime_error("Number can't be divided by zero!");
	}

	//get results
	result_ = leftNode_result / rightNode_result;
}

//visit modulus node
void Evaluate_Expression_Tree_Visitor::Visit_Modulus_Node( Modulus_Expression_Node& node)
{
	//accept left child of tree
	Evaluate_Expression_Tree_Visitor left_node;
	node.getLeftChildOfTree()->accept(left_node);
	int leftNode_result = left_node.result();

	//accept right child of tree
	Evaluate_Expression_Tree_Visitor right_node;
	node.getRightChildOfTree()->accept(right_node);
	int rightNode_result = right_node.result();
	if (rightNode_result == 0) {
		throw std::runtime_error("Number can't be divided by zero!");
	}
	//get results
	result_ = leftNode_result % rightNode_result;
}

//visit unary node
void Evaluate_Expression_Tree_Visitor::Visit_Unary_Node( Unary_Expression_Node& node)
{
	Evaluate_Expression_Tree_Visitor unary_node;
	node.getChildOfTree()->accept(unary_node);
	//get results
	result_ = -unary_node.result();
}

void Evaluate_Expression_Tree_Visitor::Visit_Number_Node( Number_Expression_Node& node)
{
	//get results
	result_ = node.getExpression();
}

int Evaluate_Expression_Tree_Visitor::result()
{
	//return results
	return result_;
}
