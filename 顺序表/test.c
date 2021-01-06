#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void Test01()
{
    SeqList L;
    SeqListInit(&L,0);
    //尾插
    SeqListPushBack(&L,1);
    SeqListPushBack(&L,2);
    SeqListPushBack(&L,3);
    SeqListPushBack(&L,4);
    SeqListPushBack(&L,5);
    SeqListPushBack(&L,6);
    //尾删
    //SeqListPopBack(&L);
    //
    //头插
    SeqListPushFront(&L,0);

    SeqListPrint(&L);
    //头删
    SeqListPopFront(&L);
    SeqListPrint(&L);

    printf("%d\n",SeqListFind(&L,3));
    //
    //
    //
    //
}

int main()
{
    Test01();
    return 0;
}
