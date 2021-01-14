#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Heap
{
    DataType* arr;
    int size;
    int capacity;
}Heap;


void swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp; 
}
//向上调整算法 
//
//
//建立的是小根堆
//
//arr——待调整的堆
void upAdjust(DataType* arr,int child)
{
    int parent=(child-1)/2;
    while(child>0)
    {
        //比较子节点和父节点的大小
        if(arr[child]<arr[parent])
        {
            swap(&arr[parent],&arr[child]);
            //调整
            child=parent;
            parent=(child-1)/2;
        }
        else
        {
            break;
        }
    }
}

//向下调整算法
void downAdjust(DataType* arr,int n,int root)
{
    int parent=root;
    int child=parent*2+1;
    while(child<n)
    {
        //找出左右孩子中小的那一个
        if(child+1<n && arr[child+1]<arr[child])
        {
            child++;
        }
        //如果
        if(arr[parent]>arr[child])
        {
            swap(&arr[parent],&arr[child]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }
}

//构建堆
void HeapBuild(Heap* hp,DataType* arr,int n)
{
    hp->arr=(DataType*)malloc(sizeof(DataType)*n);
    memcpy(hp->arr,arr,sizeof(DataType)*n);
    hp->size=n;
    hp->capacity=n;
    //建堆，使用向下调整算法，从最后一个非叶子结点开始
    for(int i=(n-1-1)/2;i>=0;i--)
    {
        downAdjust(hp->arr,hp->size,i);
    }
}

//销毁堆
void HeapDestory(Heap* hp)
{
    free(hp->arr);
    hp->arr=NULL;
    hp->size=hp->capacity=0;
}

//堆的插入
void HeapPush(Heap* hp,DataType x)
{
    if(hp->size==hp->capacity)
    {
        hp->capacity*=2;
        hp->arr=(DataType*)realloc(hp->arr,sizeof(DataType)*hp->capacity);
    }
    hp->arr[hp->size]=x;
    hp->size++;
    //向上调整
    upAdjust(hp->arr,hp->size-1);
}

//堆的删除
void HeapPop(Heap* hp)
{
    swap(&hp->arr[0],&hp->arr[hp->size-1]);

    hp->size--;
    //向下调整
    downAdjust(hp->arr,hp->size,0);
}

//取堆顶的数据
DataType HeapTop(Heap* hp)
{
    return hp->arr[0];
}

//堆的数据个数
int HeapSize(Heap* hp)
{
    return hp->size;
}

//堆的判空
int HeapEmpty(Heap* hp)
{
    if(hp->size==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//打印
void HeapPrint(Heap* hp)
{
    for(int i=0;i<hp->size;i++)
    {
        printf("%d ",hp->arr[i]);
    }
    printf("\n");
}

//堆排序
void HeapSort(int *arr,int n)
{
    for(int i=(n-1-1)/2;i>=0;i--)
    {
        downAdjust(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(&arr[i],&arr[0]);
        downAdjust(arr,i,0);
    }
}
