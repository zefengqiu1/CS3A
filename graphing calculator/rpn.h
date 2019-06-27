#ifndef RPN_H
#define RPN_H
#include <iostream>
#include "token.h"
#include "number.h"
#include "operator.h"
#include "../stack_queue/stack.h"
#include "../stack_queue/queue.h"
using namespace std;

class RPN
{
public:
    RPN(Queue<Token*> input);
    RPN(string input);
    ~RPN();
    double rpn(double value=0);

private:
    Queue<Token*> _input;
    string _expression;
    double _variable;
   // bool _degree=false;
};

#endif // RPN_H
