#include "rpn.h"
#include <cmath>
#define PI 3.1415927

RPN::RPN(Queue<Token*>input)
{
    _input=input;

}

RPN::RPN(string input)
{
    _expression=input;
}

double RPN::rpn(double value)
{
    double number1,number2,result,final_result;
    Stack<double> s;
    while(!_input.empty())
    {
        Token* p=_input.pop();
        switch (p->type()) {
            case Var:
                number1=value;
                s.push(number1);
            break;
            case oper:
                if(static_cast<Operator*>(p)->OP()=="sin")
                {
                    if(!s.empty())
                    {
                           number1=s.pop();
                    }else
                    {
                        throw "error";
                    }


                   // result=sin(number1*(PI/180));
                    result=sin(number1);
                    s.push(result);
                    break;
                }else if(static_cast<Operator*>(p)->OP()=="cos")
                {
                    if(!s.empty())
                    {
                         number1=s.pop();
                    }else
                    {
                        throw "error";
                    }


                  // result=cos(number1*(PI/180));
                    result=cos(number1);
                    s.push(result);
                    break;
                }else if(static_cast<Operator*>(p)->OP()=="tan")
                {
                    if(!s.empty())
                    {
                           number1=s.pop();
                    }else
                    {
                        throw "error";
                    }



                    //result=tan(number1*(PI/180));
                    result=tan(number1);

                    s.push(result);
                    break;
                }else if(static_cast<Operator*>(p)->OP()=="csc")
                {
                    if(!s.empty())
                    {
                         number1=s.pop();
                    }


                   // result=1/sin(number1*(PI/180));
                    result=1/sin(number1);

                    s.push(result);
                    break;
                }else if(static_cast<Operator*>(p)->OP()=="sec")
                {

                    if(!s.empty())
                    {
                        number1=s.pop();
                    }else
                    {
                        throw "error";
                    }

                    //   result=1/cos(number1*(PI/180));
                         result=1/cos(number1);
                    s.push(result);
                    break;
                }else if(static_cast<Operator*>(p)->OP()=="cot")
                {
                    if(!s.empty())
                    {
                         number1=s.pop();
                    }else
                    {
                        throw "error";
                    }


                 //  result=1/tan(number1*(PI/180));
                      result=1/tan(number1);
                    s.push(result);
                    break;
                }

                    switch(static_cast<Operator*>(p)->OP()[0])
                    {
                    case '+':
                        if(!s.empty())
                        {
                            number1=s.pop();
                        }else
                        {
                            throw "error";
                        }


                        if(!s.empty())
                        {
                            number2=s.pop();
                            result=number1+number2;
                            s.push(result);
                        }else
                        {
                             throw "error";
                        }


                        break;
                    case '-':
                        if(!s.empty())
                        {
                             number1=s.pop();
                        }else
                        {
                            throw "error";
                        }

                        if(s.empty())
                        {
                            result=number1*(-1);
                            s.push(result);
                        }else
                        {
                            if(!s.empty())
                            {
                                number2=s.pop();
                            }else
                            {
                                throw "error";
                            }
                            result=number2-number1;
                            s.push(result);
                        }

                        break;
                    case '*':
                         if(!s.empty())
                         {
                              number1=s.pop();
                         }else
                         {
                             throw "error";
                         }

                        if(!s.empty())
                        {
                            number2=s.pop();
                            result=number1*number2;
                            s.push(result);
                        }else
                        {
                             throw "error";
                        }

                        break;
                    case '/':
                        if(!s.empty())
                        {
                            number1=s.pop();
                        }else
                        {
                            throw "error";
                        }

                        if(!s.empty())
                        {
                            number2=s.pop();
                        }else
                        {
                             throw "error";
                        }

                        if(number1==0)
                        {
                            throw "Division by zero condition!";
                        }
                        result=number2/number1;
                        s.push(result);
                        break;
                    case '^':
                        if(!s.empty())
                        {
                           number1=s.pop();
                        }else
                        {
                            throw "error";
                        }

                        if(!s.empty())
                        {
                            number2=s.pop();
                            result=pow(number2,number1);
                            s.push(result);
                        }else
                        {
                            throw "error";
                        }
                        break;
                    }
                    break;
           case number:
               double double_number=static_cast<Number*>(p)->doublenumber();
               s.push(double_number);
               break;

        }

    }

    if(!s.empty())
    {
        final_result=s.pop();
    }else
    {
        throw "error";
    }

    return final_result;
}

RPN::~RPN(){
    while(!_input.empty()){
        Token* d;
        d=_input.pop();
        delete d;
    }
}
