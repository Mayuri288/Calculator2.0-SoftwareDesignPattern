#ifndef _NUMBER_EXPRESSION_NODE_
#define _NUMBER_EXPRESSION_NODE_

#include "Expression_Node.h"

class Number_Expression_Node : public Expression_Node {
public:
    //constructor for Number_Expression_Node
    Number_Expression_Node(void);
    //parametrized constructor
    Number_Expression_Node(int number);
    //accept visitor
    virtual void accept(Expression_Node_Visitor& v);
    //destructor for Number_Expression_Node
    virtual ~Number_Expression_Node(void);
    //check precedence
    virtual int precedence(void);
    //evaluate expression
    virtual int evaluate(void);
    //get expression
    virtual int getExpression(void);
    //check for expression of operator
    virtual char exp(void);
protected:
    int number;
};
#endif // _NUMBER_EXPRESSION_NODE_