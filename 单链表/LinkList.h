#pragma once

typedef int DataType;

//链表的结点结构
typedef struct ListNode
{
    //数据域
    DataType data;
    //指针域
    struct ListNode* next;
}ListNode;

//增删查改的接口
//
//动态申请一个节点
ListNode* BuyListNode(DataType x);
//打印
void ListPrint(ListNode* plist);
//尾插
void ListPushBack(ListNode** pplist,DataType x);
//头插
void ListPushFront(ListNode** pplist,DataType x);
//尾删
void ListPopBack(ListNode** pplist);
//头删
void ListPopFront(ListNode** pplist);
//查找
ListNode* ListFind(ListNode* plist,DataType x);
//在pos位置之后插入x
void ListInsertAfter(ListNode* pos,DataType x);
//在pos位置之后的值
void ListEraseAfter(ListNode* pos);
//销毁
void ListDestory(ListNode** pplist);
