#include "LinkList.h"
#include <stdio.h>

void test01()
{
    ListNode* plist=NULL;
    //尾插
    ListPushBack(&plist,1);
    ListPushBack(&plist,2);
    ListPushBack(&plist,3);
    ListPushBack(&plist,4);
    ListPushBack(&plist,5);
    //
    ListPrint(plist);
    //头插
    ListPushFront(&plist,0);
    // 
    ListPrint(plist);
    //
    ListNode* tmp=ListFind(plist,3);
    //pos位置之后插入
    ListInsertAfter(tmp,3);
    ListPrint(plist);
    //pos位置之后删除
    ListNode* tmp1=ListFind(plist,2);
    ListEraseAfter(tmp1);
    ListPrint(plist);

}

int main()
{
    test01();
    return 0;
}

