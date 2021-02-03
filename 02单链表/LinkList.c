#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


//申请节点空间
ListNode* BuyListNode(DataType x)
{
    //申请空间
    ListNode* node=(ListNode*)malloc(sizeof(ListNode));
    //数据域赋值
    node->data=x;
    //指针域赋值
    node->next=NULL;
    return node;
}
//打印
void ListPrint(ListNode* plist)
{
    //定义结点指针
    ListNode* cur=plist;
    //循环遍历链表
    while(cur!=NULL)
    {
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}
//尾插
void ListPushBack(ListNode** pplist,DataType x)
{
    //申请新结点
    ListNode* newnode=BuyListNode(x);
    //判断链表是否为空
    if(*pplist==NULL)
    {
        //链表为空，直接插入
        *pplist=newnode;
    }
    else
    {
        //若链表不为空，则找到链表尾插入新结点
        //
        //定义tail指针寻找链表尾结点
        ListNode* tail=*pplist;
        //循环遍历链表
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        //在尾部插入新结点
        tail->next=newnode;
    }
}
//头插
void ListPushFront(ListNode** pplist,DataType x)
{
    //申请结点空间
    ListNode* newnode=BuyListNode(x);
    //判断链表是否为空
    if(*pplist==NULL)
    {
        //1.若为空，直接插入
        *pplist=newnode;
    }
    else
    {
        //2.若不为空，新结点的指针域指向链表的头
        newnode->next=*pplist;
        //插入完成后，让*plist重新指向头结点
        *pplist=newnode;
    }
}
//尾删
void ListPopBack(ListNode** pplist)
{
    //双指针
    //pre指针指向删除结点的前一个指针
    ListNode* pre=NULL;
    //tail指向要删除的结点
    ListNode* tail=*pplist;
    //
    //1.链表为空或者只有一个节点
    if(tail==NULL||tail->next==NULL)
    {
        //释放内存
        free(tail);
        *pplist=NULL;
    }
    //2.有多个结点
    else
    {
        while(tail->next!=NULL)
        {
            pre=tail;
            tail=tail->next;
        }
        //删除表尾结点
        pre->next=NULL;
        //释放空间
        free(tail);
    }
}
//头删
void ListPopFront(ListNode** pplist)
{
    ListNode* cur=*pplist;
    //1.链表为空
    if(cur==NULL)
    {
        return ;
    }
    //2.链表有一个结点
    else if(cur->next==NULL)
    {
        free(cur);
        *pplist=NULL;
    }
    //有多个结点
    else
    {
        //next指针指向头结点的下一个结点
        ListNode* next=cur->next;
        //释放空间
        free(cur);
        //*pplist指向新的头
        *pplist=next;
    }
}
//查找
ListNode* ListFind(ListNode* plist,DataType x)
{
    //定义cur指针用来遍历
    ListNode* cur=plist;
    //遍历链表
    while(cur!=NULL)
    {
        if(cur->data==x)
        {
            return cur;
        }
        cur=cur->next;
    }
    //找不到返回空
    return NULL;
}
//在pos位置之后插入x
void ListInsertAfter(ListNode* pos,DataType x)
{
    ListNode* newnode=BuyListNode(x);
    newnode->next=pos->next;
    pos->next=newnode;
}
//删除pos位置之后的结点
void ListEraseAfter(ListNode* pos)
{
    //next指针记录pos位置的下一个结点
    ListNode* next=pos->next;
    if(next!=NULL)
    {
        pos->next=next->next;
        free(next);
    }
}
//销毁
void ListDestory(ListNode** pplist)
{
    ListNode* cur=*pplist;
    while(cur!=NULL)
    {
        ListNode* next=cur->next;
        free(cur);
        cur=next;
    }
    *pplist=NULL;
}
