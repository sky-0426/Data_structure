#include <stdio.h>

void ShellSort(int arr[],int n)
{
    int gap=n;
    while(gap>1)
    {
        gap=gap/3+1;
        //3个间隔为gap的组同时交叉排序
        for(int i=0;i<n-gap;i++)
        {
            int end=i;
            int tmp=arr[end+gap];
            while(end>=0)
            {
                if(arr[end]>tmp)
                {
                    arr[end+gap]=arr[end];
                    end-=gap;
                }
                else
                {
                    break;
                }
            }
            arr[end+gap]=tmp;
        }
    }
}

int main()
{
    int arr[]={4,3,5,1,2};
    int len=sizeof(arr)/sizeof(arr[0]);
    ShellSort(arr,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

