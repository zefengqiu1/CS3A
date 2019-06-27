#include "rparen.h"


Rparen::Rparen(string rparenthese):Token(Rparenthese)
{
    _Rparentheses=rparenthese;
}

int Rparen::type()
{
    return Token::type();
}

string Rparen::getparenthese()
{
    return _Rparentheses;
}

void Rparen::print()
{
    cout<<_Rparentheses;
}
