#include <stdio.h>

//快速排序
//首先选取一个基准base,然后将数组按照选取的基准base进行划分，
//将所有比base小的元素放到base的左边，所有比base大的元素放到basede右边i
//
void swap(int* left,int* right)
{
    int tmp=*left;
    *left=*right;
    *right=tmp;
}

int quick_sort01(int arr[],int begin,int end)
{
    int key=arr[end];
    int i=begin-1;
    for(int j=begin;j<end;j++)
    {
        if(arr[j]<key)
        {
            i++;
            //交换arr[i]和arr[j]
            //int tmp=arr[i];
            //arr[i]=arr[j];
            //arr[j]=tmp;
            swap(&arr[i],&arr[j]);
        }
    }
    //交换arr[i+1]和arr[end]
    //int tmp=arr[i+1];
    //arr[i+1]=arr[end];
    //arr[end]=tmp;
    swap(&arr[i+1],&arr[end]);
    //返回基准的下标
    return i+1;
}
void quicksort(int arr[],int begin,int end)
{
    if(begin<end)
{
        int index=quick_sort01(arr,begin,end);
        quicksort(arr,begin,index-1);
        quicksort(arr,index+1,end);
    }
}
int main()
{
    int arr[6]={2,4,5,3,1,2};
    int len=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,len-1);
    for(int i=0;i<len;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

