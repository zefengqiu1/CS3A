#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../stack_queue/queue.h"
#include "../stack_queue/stack.h"
#include "operator.h"
#include "token.h"
//#include "lparen.h"
#include "number.h"
//#include "rparen.h"


class shunting_yard
{
public:
    shunting_yard(Queue<Token*> infix);
    Queue<Token*> postfix();
   // ~shunting_yard();

private:
     Queue<Token*> _infix;
     Queue<Token*> _postfix;
};

#endif // SHUNTING_YARD_H
