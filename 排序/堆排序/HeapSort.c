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

    /*
    //先保存当前结点的下标
    int max=index;
    //左右孩子的数组下标
    int leftchild=2*index+1;
    int rightchild=2*index+2;
    //
    //下标存在，且找出大的那一个
    if(leftchild<len && arr[leftchild]>arr[max])
    {
        max=leftchild;
    }
    if(rightchild<len && arr[rightchild]>arr[max])
    {
        max=rightchild;
    }
    //判断需不需要交换
    if(max!=index)
    {
        swap(&arr[max],&arr[index]);
        //交换完之后，可能不再满足堆，所以需要递归调整
        HeapAdjust(arr,max,len);
    }
    */
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

