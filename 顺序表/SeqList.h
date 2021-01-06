#pragma once
#include <stdio.h>

//顺序表存储的数据类型
typedef int DataType;

typedef struct SeqList
{
    //指向动态开辟的数组
    DataType* array;
    //有效数据个数
    size_t size;
    //容量空间大小
    size_t capacity;
}SeqList;

//增删查改的接口
//
//顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity);
//顺序表的销毁
void SeqListDestory(SeqList* psl);
//打印
void SeqListPrint(SeqList* psl);
//空间检查，size==capacity，说明容量满了，要进行扩容
void CheckCapacity(SeqList* psl);
//尾插
void SeqListPushBack(SeqList* psl,DataType x);
//尾删
void SeqListPopBack(SeqList* psl);
//头插
void SeqListPushFront(SeqList* psl,DataType x);
//头删
void SeqListPopFront(SeqList* psl);
//查找
int SeqListFind(SeqList* psl,DataType x);
//在pos位置插入x
void SeqListInsert(SeqList* psl,size_t pos,DataType x);
//删除pos位置的值
void SeqListErase(SeqList* psl,size_t pos);
