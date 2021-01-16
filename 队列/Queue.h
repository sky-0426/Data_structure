#pragma once

typedef int DataType;
//队列的链式结构
//
//队列的结点结构
typedef struct QueueNode
{
    DataType data;
    struct QueueNode* next;
}QueueNode;
//队列的结构
typedef struct Queue
{
    //队头指针
    QueueNode* front;
    //队尾指针
    QueueNode* rear;
}Queue;

//初始化
void QueueInit(Queue* q);
//队尾入队
void QueuePush(Queue* q,DataType x);
//队头出队
void QueuePop(Queue* q);
//获取队列头部元素
DataType QueueFront(Queue* q);
//获取队列尾部元素
DataType QueueBack(Queue* q);
//获取队列有效元素个数
int QueueSize(Queue* q);
//检测队列是否为空
int QueueEmpty(Queue*q);
//销毁队列
void QueueDestory(Queue* q);

