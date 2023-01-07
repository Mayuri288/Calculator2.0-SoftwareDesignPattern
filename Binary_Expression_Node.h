
#ifndef _BINARY_EXPRESSION_NODE_H
#define _BINARY_EXPRESSION_NODE_H
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include "Expression_Node.h"

class Binary_Expression_Node:public Expression_Node {
public:
    //constructor for Binary_Expression_Node
    Binary_Expression_Node(void);
    // parametrized constructor for Binary_Expression_Node
    Binary_Expression_Node(Expression_Node* left_child, Expression_Node* right_child);
    //destructor for Binary_Expression_Node
    virtual ~Binary_Expression_Node(void);
    //evaluate expressions
    virtual int evaluate(void);
    //left child of tree
    virtual Expression_Node* getLeftChildOfTree() = 0;
    //right child of tree
    virtual Expression_Node* getRightChildOfTree() = 0;
    //execute expressions
    virtual int executeExpression(int left_child, int right_child) = 0;
    //check precedence
    virtual int precedence(void) = 0;
    //get expression of operators
    virtual char exp(void) = 0;
    //accept visitor
    virtual void accept(Expression_Node_Visitor& v) = 0;
protected:
    Expression_Node* right_child;
    Expression_Node* left_child;
};
#endif // BINARY_EXPRESSION_NODE