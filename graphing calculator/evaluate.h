#ifndef EVALUATE_H
#define EVALUATE_H
#include<iostream>
#include "../stack_queue/queue.h"
#include "token.h"
#include "number.h"
#include "operator.h"
#include "variable.h"
#include "lparen.h"
#include "rparen.h"
#include "shunting_yard.h"
#include "rpn.h"

using namespace std;

class Evaluate
{
public:
    Evaluate(string input);
    ~Evaluate();
    double eval(double var=0);

private:
    Queue<Token*> _input;
    bool _shunting = false;
};

#endif // EVALUATE_H
