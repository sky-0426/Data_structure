#include "Heap.h"
#include <stdio.h>


//TopK问题
void TopK(int* arr,int n,int k)
{
    Heap hp;
    //建一个有K个元素的堆
    HeapBuild(&hp,arr,k);
    for(int i=k;i<n;++i)
    {
        if(arr[i]>arr[0])
        {
            HeapPop(&hp);
            HeapPush(&hp,arr[i]);
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",HeapTop(&hp));
        HeapPop(&hp);
    }
    printf("\n");
}


int main()
{
    /*
    int arr[9]={7,1,3,10,5,2,8,9,6};
    Heap hp;
    HeapBuild(&hp,arr,9);
    HeapPrint(&hp);

    HeapPush(&hp,4);
    HeapPrint(&hp);

    printf("%d\n",HeapTop(&hp));

    HeapPop(&hp);
    HeapPrint(&hp);

    HeapDestory(&hp);
    */

    int arr1[9]={7,1,3,10,5,2,8,9,6};
    int len=sizeof(arr1)/sizeof(arr1[0]);
    
    TopK(arr1,len,3);

    /*
    HeapSort(arr1,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    */
    return 0;
}

