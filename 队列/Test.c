#include "Queue.h"
#include <stdio.h>

void test()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);

    printf("%d\n",QueueSize(&q));

    while(!QueueEmpty(&q))
    {
        printf("%d\n",QueueFront(&q));
        QueuePop(&q);
    }
    
}


int main()
{
    test();
    return 0;
}

