#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//计数排序

void CountSort(int arr[],int n)
{
    int min=arr[0],max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    //计算数据的范围
    int len=max-min+1;
    int* tmp=(int*)malloc(len*sizeof(int));
    memset(tmp,0,sizeof(int)*len);
    //存放在相对位置
    for(int i=0;i<n;i++)
    {
        tmp[arr[i]-min]++;
    }
    int index=0;
    for(int i=0;i<len;i++)
    {
        while(tmp[i]--)
        {
            arr[index++]=i+min;
        }
    }
}


int main()
{
    int arr[]={0,5,7,9,6,3,4,5,2,8,6,9,2,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    CountSort(arr,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

