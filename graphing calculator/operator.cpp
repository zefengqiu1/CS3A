#include "operator.h"

Operator::Operator():Token(3)
{
    _precedence=0;
    _op="None";
}
Operator::Operator(string op):Token(3)
{
    _op=op;
    if(op=="+"||op=="-")
    {
        _precedence=1;
    }else if(op=="^")
    {
        _precedence=3;
    }else if(op=="*"||op=="/")
    {
        _precedence=2;
    }else if(op=="sin"||op=="cos"||op=="tan"||op=="sec"||op=="cot"||op=="csc")
    {
        _precedence=4;

    }

//    else if( op=="-")
//    {
//         _precedence=5;
//    }




}

int Operator::prec()
{
    return _precedence;
}

string Operator::OP()
{
    return _op;
}

int Operator::type()
{
    return Token::type();
}
void Operator::print()
{
    cout<<_op;
}
