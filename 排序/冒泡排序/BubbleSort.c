#include <stdio.h>

//算法思想：
//1、比较相邻元素。如果第一个比第二个大，就交换他们两个；
//2、对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对时。
//3、针对的所有的元素(除了最后一个)重复上述步骤
//4、持续对越来越少的元素重复上述步骤，直到没有任何一对数字需要比较
//
//第一版的冒泡排序
void bubblesort01(int arr[],int n)
{
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

//第二版的冒牌排序
//利用flag标记变量，如果在本轮排序中，元素有交换，则说明数组无需
//如果没有元素交换，说明数列有序，直接跳出大循环
void bubblesort02(int arr[],int n)
{
    for(int i=0;i<n;++i)
    {
        //标记数组是否有序
        int flag=1;
        for(int j=0;j<n-i-1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                //有元素交换，所以不是有序的，标记变为false
                flag=0;
            }
        }
        if(flag)
        {
            break;
        }
    }
}

//可以在每一轮的排序后，记录下最后一次元素交换的位置，
//那个位置也就是无序数组的边界，再往后就是有序区域
void bubblesort03(int arr[],int n)
{
    //记录最后一次交换的位置
    int change=0;
    //无序数组的边界，每次比较到此为止
    int index=n-1;
    for(int i=0;i<n;++i)
    {
        int flag=1;
        for(int j=0;j<index;++j)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                //有元素交换，标记变为false
                flag=0;
                //记录最后一次交换元素的位置，更新无序数组的边界位置
                change=j;
            }
        }
        index=change;
        if(flag==1)
        {
            break;
        }
    }
}

int main()
{
    int arr[10]={1,3,5,7,8,0,9,2,4,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    bubblesort03(arr,len);
    for(int i=0;i<len-1;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

