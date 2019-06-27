#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"

class Number:public Token
{
public:
    Number();
    Number(string s);
    void print();
    int type();
    virtual double doublenumber();

private:
    double _double_num;

};

#endif // NUMBER_H
