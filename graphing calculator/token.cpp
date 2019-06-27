#include "token.h"

Token::Token():_str("q"),_type(1)
{

}

Token::Token(string s):_str(s),_type(1)
{

}

Token::Token(int type):_type(type)
{

}

void Token::print()
{
    cout<<_str;
}

int Token::type()
{
    return _type;
}
