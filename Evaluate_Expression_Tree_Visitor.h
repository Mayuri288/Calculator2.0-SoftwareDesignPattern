#ifndef EVALUATE_EXPRESSION_TREE_VISITOR_H_
#define EVALUATE_EXPRESSION_TREE_VISITOR_H_
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"
#include "Expression_Node_Visitor.h"

class Evaluate_Expression_Tree_Visitor : public Expression_Node_Visitor {
public:
    //constructor for Evaluate_Expression_Tree_Visitor
    Evaluate_Expression_Tree_Visitor(void);
    //destructor for Evaluate_Expression_Tree_Visitor
    virtual ~Evaluate_Expression_Tree_Visitor(void);
    //visit addition node
    virtual void Visit_Addition_Node(Addition_Expression_Node& node);
    //visit subtraction node
    virtual void Visit_Subtraction_Node( Subtraction_Expression_Node& node);
    //visit division node
    virtual void Visit_Division_Node( Division_Expression_Node& node);
    //visit multiplication node
    virtual void Visit_Multiplication_Node( Multiplication_Expression_Node& node);
    //visit number node
    virtual void Visit_Number_Node( Number_Expression_Node& node);
    //visit modulus node
    virtual void Visit_Modulus_Node( Modulus_Expression_Node& node);
    //visit unary node
    virtual void Visit_Unary_Node( Unary_Expression_Node& node);
    int result(void);
private:
    int result_;
};
#endif