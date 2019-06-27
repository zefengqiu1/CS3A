#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

const int number=2;
const int oper=3;
const int Lparenthese=0;
const int Rparenthese=1;
const int Var=4;


class Token
{
public:
    Token();
    Token(string s);
    Token(int type);
    virtual void print();
    virtual int type();

private:
    string _str;
    int _type;
};

#endif // TOKEN_H
