#include "Stack.h"
#include <stdio.h>

int main()
{
    Stack s;
    StackInit(&s);
    StackPush(&s,1);
    StackPush(&s,2);
    StackPush(&s,3);
    StackPush(&s,4);
    while(!StackEmpty(&s))
    {
        printf("%d\n",StackTop(&s));
        StackPop(&s);
    }
    return 0;
}

