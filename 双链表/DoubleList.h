#pragma once

typedef int Datatype;

//结点结构
typedef struct ListNode
{
    Datatype data;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;

//接口
//
//创建返回链表的头结点
ListNode* ListCreate();
//销毁
void ListDestory(ListNode* plist);
//打印
void ListPrint(ListNode* plist);
//尾插
void ListPushBack(ListNode* plist,Datatype x);
//尾删
void ListPopBack(ListNode* plist);
//头插
void ListPushFront(ListNode* plist,Datatype x);
//头删
void ListPopFront(ListNode* plist);
//查找
ListNode* ListFind(ListNode* plist,Datatype x);
//在pos的前面插入x
void ListInsert(ListNode* plist,Datatype x);
//删除pos位置的值
void ListErase(ListNode* plist);
