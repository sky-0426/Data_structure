#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end)
{
    //int* tmp=(int*)malloc(sizeof(int)*(end-start+1));
    int* tmp=new int[end-start+1];
    int p1=start;
    int p2=mid+1;
    int p=0;
    while(p1<=mid&&p2<=end)
    {
        if(arr[p1]<=arr[p2])
            tmp[p++]=arr[p1++];
        else
            tmp[p++]=arr[p2++];
    }
    //若左侧有剩余
    while(p1<=mid)
    {
        tmp[p++]=arr[p1++];
    }
    while(p2<=end)
    {

        tmp[p++]=arr[p2++];
    }

    for(int i=0;i<end-start+1;++i)
    {
        arr[i+start]=tmp[i];
    }
}
void MergeSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int arr[]={5,8,6,3,9,2,1,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,len-1);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

