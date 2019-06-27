#ifndef OPERATOR_H
#define OPERATOR_H


#include "token.h"

class Operator:public Token
{
public:

    Operator();
    Operator(string op);
    int prec();
    int type();
    void print();
    string OP();

private:
    int _precedence;
    string _op;

};

#endif // OPERATOR_H
