#pragma once
#include <stdio.h>
#include <stdlib.h>


//栈是限定在表尾进行插入和删除的线性表，
//允许插入和删除的一端称为栈顶，另一端称为栈底，
//不含任何元素的栈称为空栈，栈是先进后出的线性表
//
//
typedef int Datatype;
//支持动态增长的栈
typedef struct Stack
{
    Datatype* arr;
    //栈顶指针，初始化为0，指向栈顶元素的下一个位置
    int top;
    //容量
    int capacity;
}Stack;


//初始化操作，建立一个空栈
void StackInit(Stack* s)
{
    s->top=0;
    s->capacity=2;
    s->arr=(Datatype*)malloc(sizeof(Datatype)*s->capacity);
}
//销毁栈
void StackDestory(Stack* s)
{
    if(s->arr!=NULL)
    {
        free(s);
        s->arr=NULL;
        s->top=s->capacity=0;
    }
}
//入栈
void StackPush(Stack* s,Datatype x)
{
    //判断栈是否已满
    if(s->top==s->capacity)
    {
        //栈已满，进行扩容
        s->capacity=s->capacity*2;
        //申请新的空间，将之前的数据复制过去
        s->arr=(Datatype*)realloc(s->arr,sizeof(Datatype)*s->capacity);
    }
    //将数据入栈
    s->arr[s->top]=x;
    s->top++;
}
//出栈
void StackPop(Stack* s)
{
    //判断栈是否为空
    if(s->top==0)
    {
        //栈为空，直接返回
        return ;
    }
    //栈顶指针减一
    s->top--;
}
//获取栈顶元素
Datatype StackTop(Stack* s)
{
    if(s->top!=0)
    {
        //栈不为空，返回栈顶元素
        return s->arr[s->top-1];
    }
    return (Datatype)0;
}
//获取栈中的有效元素个数
int StackSize(Stack* s)
{
    return s->top;
}
//检测栈是否为空
int StackEmpty(Stack* s)
{
    return s->top==0;
}

