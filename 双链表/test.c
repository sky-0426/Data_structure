#include <stdio.h>
#include "DoubleList.h"


void test01()
{
    ListNode* l=ListCreate();
    //尾插
    ListPushFront(l,2);
    ListPushFront(l,1);
    ListPushBack(l,3);
    ListPushBack(l,4);
    ListPushBack(l,5);
    ListPrint(l);

    //头插
    ListPushFront(l,0);
    ListPrint(l);
    //尾删
    ListPopBack(l);
    ListPrint(l);
    //头删
    ListPopFront(l);
    ListPrint(l);
    //
    ListNode* tmp=ListFind(l,2);
    //
    ListInsert(tmp,2);
    ListPrint(l);

    ListErase(tmp);
    ListPrint(l);

}
int main()
{
    test01();
    return 0;
}

