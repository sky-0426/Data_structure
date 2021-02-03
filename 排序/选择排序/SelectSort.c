#include <stdio.h>

//算法思想
//1、在未选择的序列中找到最小(大)的元素，存放到排序序列的起始位置
//2、从剩余未排序的元素中继续寻找最小(大)的元素，存放到已排序序列的末尾
//3、以此类推，直到所有元素均已排序完毕

void selectsort(int arr[],int n)
{
    for(int i=0;i<n;++i)
    {
        int minindex=i;
        for(int j=i+1;j<n;++j)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        int tmp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=tmp;
    }
}

int main()
{
    int arr[8]={5,8,6,3,9,2,1,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    selectsort(arr,len);
    for(int i=0;i<len;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
