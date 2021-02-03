#include "DoubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建头结点
ListNode* ListCreate()
{
    //创建头结点
    ListNode* head=(ListNode*)malloc(sizeof(ListNode));
    if(head!=NULL)
    {
        head->next=head;
        head->prev=head;
        return head;
    }
    return NULL;
}
//销毁
void ListDestory(ListNode* plist)
{
    //定义指针指向头结点的下一个结点
    ListNode* cur=plist->next;
    while(cur!=plist)
    {
        ListNode* tmp=cur->next;
        free(cur);
        cur=tmp;
    }
    free(plist);
}
//打印
void ListPrint(ListNode* plist)
{
    ListNode* cur=plist->next;
    while(cur!=plist)
    {
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}
//尾插
void ListPushBack(ListNode* plist,Datatype x)
{
    //申请新结点空间
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    if(newnode!=NULL)
    {
        //数据域赋值
        newnode->data=x;
        //指针域赋值
        newnode->next=NULL;
        newnode->prev=NULL;
        //定义tail指针指向链表的表尾
        ListNode* tail=plist->prev;
        //插入新的节点
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=plist;
        plist->prev=newnode;    
    }
}
//尾删
void ListPopBack(ListNode* plist)
{
    assert(plist->next!=plist);
    ListNode* tail=plist->prev;
    ListNode* pre=tail->prev;
    free(tail);
    pre->next=plist;
    plist->prev=pre;
}
//头插
void ListPushFront(ListNode* plist,Datatype x)
{
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    if(newnode!=NULL)
    {
        newnode->data=x;
        newnode->next=NULL;
        newnode->prev=NULL;
        ListNode* first=plist->next;
        //插入
        plist->next=newnode;
        newnode->prev=plist;
        newnode->next=first;
        first->prev=newnode;    
    }
}
//头删
void ListPopFront(ListNode* plist)
{
    assert(plist->next!=plist);
    ListNode* first=plist->next;
    ListNode* second=plist->next->next;
    free(first);
    plist->next=second;
    second->prev=plist;
}
//查找
ListNode* ListFind(ListNode* plist,Datatype x)
{
    ListNode* cur=plist->next;
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}
//在pos的前面插入x
void ListInsert(ListNode* pos,Datatype x)
{
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    if(newnode!=NULL)
    {
        ListNode* pre=pos->prev;
        newnode->data=x;
        newnode->next=NULL;
        newnode->prev=NULL;
        //插入
        pre->next=newnode;
        newnode->prev=pre;
        newnode->next=pos;
        pos->prev=newnode;
    }      
}
//删除pos位置的结点
void ListErase(ListNode* pos)
{
    ListNode* front=pos->prev;
    ListNode* after=pos->next;
    free(pos);
    front->next=after;
    after->prev=front;
}
