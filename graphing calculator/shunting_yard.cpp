#include "shunting_yard.h"


shunting_yard::shunting_yard(Queue<Token*> infix)
{
    _infix=infix;
}

Queue<Token*>shunting_yard::postfix()
{
    Stack<Token*> s;
    while(!_infix.empty())
    {
        Token*p=_infix.pop();
        switch (p->type()) {
            case Var:
                _postfix.push(p);
            break;
            case oper:
                if(s.empty()||s.Top()->type()==Lparenthese)
                {
                    s.push(p);
                }else
                {
                    if(static_cast<Operator*>(s.Top())->prec()>=static_cast<Operator*>(p)->prec())
                    {
                        _postfix.push(s.pop());
                    }
                        s.push(p);
                }
                break;
            case number:
                _postfix.push(p);
                break;
            case Lparenthese:
        {
                s.push(p);

                    Token* temp=_infix.front();
                    if(temp->type()==oper)
                    {
                        if(static_cast<Operator*>(temp)->OP()=="-")
                        {
                            Token* a(new Number("0"));
                            _postfix.push(a);
                        }
                    }

        }
                    break;
            case Rparenthese:

                    while(s.Top()->type()!=Lparenthese)
                    {
                        _postfix.push(s.pop());
                    }
                     s.pop();
                    break;

        }
    }

    while(!s.empty())
    {
        _postfix.push(s.pop());
    }

      return _postfix;
}


//shunting_yard::~shunting_yard(){
//    while(!_infix.empty()){
//        Token* d;
//        d=_infix.pop();
//        delete d;
//    }

//    while(!_postfix.empty()){
//        Token* d;
//        d=_postfix.pop();
//        delete d;
//    }
//}
