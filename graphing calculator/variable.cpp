#include "variable.h"


Variable::Variable():Token(4)
{
    _vari="x";
}

Variable::Variable(string x):Token(4)
{
    _vari=x;
}

int Variable::type()
{
    return Token::type();
}
