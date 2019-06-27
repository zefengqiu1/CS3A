#include "lparen.h"

LParen::LParen():Token (Lparenthese)
{
   _Lparentheses="none";
}

LParen::LParen(string lparenthese):Token(Lparenthese)
{
    _Lparentheses=lparenthese;
}

string LParen::getparenthese()
{
    return _Lparentheses;
}

int LParen::type()
{
    return Token::type();
}

void LParen::print()
{
    cout<<_Lparentheses;
}
