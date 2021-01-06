#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
//增删查改接口的实现
//
//初始化
void SeqListInit(SeqList* psl,size_t capacity)
{
    assert(psl);
    //动态开辟内存
    psl->array=(DataType*)malloc(sizeof(DataType)*capacity);
    //容量设置为capacity
    psl->capacity=capacity;
    //大小设置为0
    psl->size=0;
}
//销毁
void SeqListDestory(SeqList* psl)
{
    assert(psl);
    //释放动态开辟的空间
    free(psl->array);
    //指向动态开辟内存的指针置空
    psl->array=NULL;
    //容量和大小置为0
    psl->size=psl->capacity=0;
}
//打印
void SeqListPrint(SeqList* psl)
{
    assert(psl);
    for(int i=0;i<psl->size;++i)
    {
        printf("%d ",psl->array[i]);
    }
    printf("\n");
}
//检查空间
void CheckCapacity(SeqList* psl)
{
    assert(psl);
    //如果size和capacity相等，容量已满，进行扩容
    if(psl->capacity==psl->size)
    {
        //设置新的内存
        int newcapacity=psl->capacity*2+1;
        //调整动态开辟内存的大小，将原来的数据复制到新开辟的内存
        psl->array=(DataType*)realloc(psl->array,sizeof(DataType)*newcapacity);
        //更改容量大小
        psl->capacity=newcapacity;
    }
}
//尾插
void SeqListPushBack(SeqList* psl,DataType x)
{
    assert(psl);
    SeqListInsert(psl,psl->size,x);
}
//尾删
void SeqListPopBack(SeqList* psl)
{
    assert(psl);
    SeqListErase(psl,psl->size);
}
//头插
void SeqListPushFront(SeqList* psl,DataType x)
{
    assert(psl);
    SeqListInsert(psl,0,x);
}
//头删
void SeqListPopFront(SeqList* psl)
{
    assert(psl);
    SeqListErase(psl,0);
}
//查找
int SeqListFind(SeqList* psl,DataType x)
{
    assert(psl);
    //遍历顺序表
    for(int i=0;i<psl->size;++i)
    {
        //判断是否和要查找的值相等
        if(psl->array[i]==x)
        {
            //返回下标
            return i;
        }
    }
    //返回-1
    return -1;
}
//在pos位置插入x
void SeqListInsert(SeqList* psl,size_t pos,DataType x)
{
    assert(psl);
    //插入的位置是否正确
    assert(pos<=psl->size);
    //检查线性表是否已满
    CheckCapacity(psl);

    int end=psl->size;
    while(end>pos)
    {
        //将插入位置（包括插入位置）之后的数据依次后移
        psl->array[end]=psl->array[end-1];
        end--;
    }
    //将要插入的数据插入pos位置
    psl->array[pos]=x;
    //数据的个数加一
    psl->size++;
}
//删除pos位置处的值
void SeqListErase(SeqList* psl,size_t pos)
{
    assert(psl);
    assert(pos<psl->size);
    //记录删除位置的下一个位置
    int start=pos+1;
    while(start<psl->size)
    {
        //删除位置之后的数据前移
        psl->array[start-1]=psl->array[start];
        start++;
    }
    //数据个数减一
    psl->size--;
}
