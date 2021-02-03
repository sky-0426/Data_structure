#include <stdio.h>

//1、从第一个元素开始，该元素可以认为已经被排序
//2、取出下一个元素，在已经排序的序列中从后往前扫描
//3、如果该元素大于新元素，将该元素往后移动
//4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
//5、将该元素插入到该位置后
//6、重复2-5步骤

void swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void insertsort01(int arr[],int n)
{
    for(int i=1;i<n;++i)
    {
        for(int j=i;j>0;--j)
        {
            if(arr[j]<arr[j-1])
            {
                swap(&arr[j],&arr[j-1]);
            }
        }
    }
}

void insertsort02(int arr[],int n)
{
    for(int i=1;i<n;++i)
    {
        int tmp=arr[i];
        int j=i;
        while(j>0&&arr[j-1]>tmp)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=tmp;
    }
}


int main()
{
    int arr[5]={4,5,3,1,2};
    int len=sizeof(arr)/sizeof(arr[0]);
    insertsort02(arr,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

