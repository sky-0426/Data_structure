#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void Test01()
{
    SeqList L;
    SeqListInit(&L,0);
    SeqListPushBack(&L,1);
    SeqListPushBack(&L,2);
    SeqListPushBack(&L,3);
    SeqListPushBack(&L,4);
    SeqListPushBack(&L,5);
    SeqListPushBack(&L,6);
    SeqListPrint(&L);
}

int main()
{
    Test01();
    return 0;
}
