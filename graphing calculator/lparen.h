#ifndef LPAREN_H
#define LPAREN_H
#include "token.h"
class LParen:public Token
{
public:
    LParen();
    LParen(string lparenthese);
    int type();
    void print();
    string getparenthese();
private:
   string _Lparentheses;
};

#endif // LPAREN_H
