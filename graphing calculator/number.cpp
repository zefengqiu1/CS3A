#include "number.h"


Number::Number():Token(2)
{
    _double_num=0;
}

Number::Number(string s):Token(2)
{
    _double_num=stod(s);
}

void Number::print()
{
    cout<<_double_num;
}

int Number::type()
{
    return Token::type();
}
double Number::doublenumber()
{
    return _double_num;
}
