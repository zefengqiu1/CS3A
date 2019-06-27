#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"
#include <iostream>

class Variable :public Token
{
public:
    Variable();
    Variable(string va);
    int type();

private:
    string _vari;
};
#endif // VARIABLE_H
