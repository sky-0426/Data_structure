#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

//初始化
void QueueInit(Queue* q)
{
    q->front=NULL;
    q->rear=NULL;
}

//队列队尾入队
void QueuePush(Queue* q,DataType x)
{
    //申请节点空间
    QueueNode* newnode=(QueueNode*)malloc(sizeof(QueueNode));
    //结点赋值
    newnode->data=x;
    newnode->next=NULL;
    //判断队列是否为空
    if(q->front==NULL)
    {
        //为空，直接插入
        q->front=q->rear=newnode;
    }
    else
    {
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
//队列队头出队
void QueuePop(Queue* q)
{
    //判断队列是否为空
    if(q->front==NULL)
    {
        return ;
    }
    //定义临时指针存储队头指针的下一个元素
    QueueNode* tmp=q->front->next;
    free(q->front);
    q->front=tmp;
}
//获取队列的头部元素
DataType QueueFront(Queue* q)
{
    return q->front->data;
}
//获取队列的尾部元素
DataType QueueBack(Queue* q)
{
    return q->rear->data;
}
//获取队列中有效元素个数
int QueueSize(Queue* q)
{
    QueueNode* cur;
    int count=0;
    for(cur=q->front;cur;cur=cur->next)
    {
        count++;
    }
    return count;
}
//检测队列是否为空
int QueueEmpty(Queue* q)
{
    return q->front==NULL;
}
//销毁队列
void QueueDestory(Queue* q)
{
    if(q->front==NULL)
    {
        return ;
    }
    while(q->front)
    {
        QueuePop(q);
    }
}
