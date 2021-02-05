#include <stdio.h>

//快速排序
//首先选取一个基准base,然后将数组按照选取的基准base进行划分，
//将所有比base小的元素放到base的左边，所有比base大的元素放到basede右边i

void swap(int* left,int* right)
{
    int tmp=*left;
    *left=*right;
    *right=tmp;
}

//挖坑法
//arr:待排序的数组
//start:起始下标
//end:结束下标
int quick01(int arr[],int start,int end)
{
    //取第一个元素作为基准
    int tmp=arr[start];
    int left=start;
    int right=end;
    //记录坑的位置
    int index=start;
    while(right>=left)
    {
        //右边的指针开始比较
        while(right>=left)
        {
            if(arr[right]<tmp)
            {
                arr[left]=arr[right];
                index=right;
                left++;
                break;
            }
            right--;
        }
        //左边的指针开始比较
        while(right>=left)
        {
            if(arr[left]>tmp)
            {
                arr[right]=arr[left];
                index=left;
                right--;
                break;
            }
            left++;
        }
    }
    arr[index]=tmp;
    //返回基准的位置
    return index;
}

//指针交换法
//
//
//
int  quick02(int arr[],int start,int end)
{
    int tmp=arr[start];
    int left=start;
    int right=end;
    while(left!=right)
    {
        //right指针
        while(left<right&&arr[right]>tmp)
        {
            right--;
        }
        while(left<right&&arr[left]<=tmp)
        {
            left++;
        }
        if(left<right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    arr[start]=arr[left];
    arr[left]=tmp;
    return left;
}

void quicksort(int arr[],int start,int end)
{
    if(start>=end)
        return ;
    //得到基准元素的位置
    int index=quick02(arr,start,end);
    quicksort(arr,start,index-1);
    quicksort(arr,index+1,end);
}

int main()
{
    int arr[]={4,7,6,5,3,2,8,1,4};
    int len=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,len-1);
    for(int i=0;i<len;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
