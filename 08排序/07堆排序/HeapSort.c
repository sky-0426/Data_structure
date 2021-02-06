#include <stdio.h>
void swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


//arr——待调整的数组
//index——待调整结点的下标
//len——数组的长度
void HeapAdjust(int arr[],int index,int len)
{
    int parent=index;
    int child=parent*2+1;
    while(child<len)
    {
        if(child+1<len && arr[child+1]<arr[child])
        {
            child++;
        }
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

void HeapSort(int arr[],int n)
{
    //初始化堆
    for(int i=(n-1-1)/2;i>=0;i--)
    {
        HeapAdjust(arr,i,n);
    }
    //交换堆顶元素和最后一个元素
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        //将交换完之后，剩下的数组进行调整
        HeapAdjust(arr,0,i);
    }
    
}
int main()
{
    int arr[]={4,2,8,0,5,7,1,3,9};
    int len=sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

