#ifndef RPAREN_H
#define RPAREN_H

#include "token.h"

class Rparen:public Token
{
public:
    Rparen(string rparenthese);
    int type();
    void print();
    string getparenthese();
private:
   string _Rparentheses;
};
#endif // RPAREN_H
