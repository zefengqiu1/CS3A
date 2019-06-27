#include "evaluate.h"
#include "rpn.h"

Evaluate::Evaluate(string input)
{
    string number;
    string tri;

    for(int i =0;i<input.length();i++)
    {
        if(isdigit(input[i]))
        {
             number+=input[i];
             continue;
        }

        switch (input[i]) {

        case 'x':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                if(tri=="sin"){_input.push(new Operator(tri));}
                if(tri=="cos"){_input.push(new Operator(tri));}
                if(tri=="tan"){_input.push(new Operator(tri));}
                if(tri=="sec"){_input.push(new Operator(tri));}
                if(tri=="csc"){_input.push(new Operator(tri));}
                if(tri=="cot"){_input.push(new Operator(tri));}
                if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }
            _input.push(new Variable("x"));
            break;
         case '+':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                 tri.clear();
            }

            _input.push(new Operator("+"));

            break;
        case '-':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

             _input.push(new Operator("-"));

           break;
        case '*':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

            _input.push(new Operator("*"));

           break;
        case '/':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

            _input.push(new Operator("/"));

           break;
        case '^':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

            _input.push(new Operator("^"));

           break;
        case ')':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();

            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

             _input.push(new Rparen(")"));

           break;
        case '(':
            if(!number.empty())
            {
                  _input.push(new Number(number));
                  number.clear();
            }
            if(!tri.empty())
            {

                 if(tri=="sin"){_input.push(new Operator(tri));}
                 if(tri=="cos"){_input.push(new Operator(tri));}
                 if(tri=="tan"){_input.push(new Operator(tri));}
                 if(tri=="sec"){_input.push(new Operator(tri));}
                 if(tri=="csc"){_input.push(new Operator(tri));}
                 if(tri=="cot"){_input.push(new Operator(tri));}
                 if(tri=="pi"){_input.push(new Number("3.14"));}
                tri.clear();
            }

            _input.push(new LParen("("));

            break;
            default:
            tri+=input[i];
            break;
        }
    }


    if(!number.empty())
    {
        _input.push(new Number(number));
    }
}

Evaluate::~Evaluate(){
    while(!_input.empty()){
        Token* d;
        d=_input.pop();
        delete d;
    }
}
double Evaluate::eval(double var)
{
//    if(!_shunting){
//        shunting_yard sy(_input);
//        _input = sy.postfix();
//        _shunting = true;
//    }

//    RPN b(_input);
//    return b.rpn(var);


        shunting_yard sy(_input);
        RPN b(sy.postfix());
        return b.rpn(var);

}
