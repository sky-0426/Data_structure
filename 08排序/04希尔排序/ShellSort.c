#include <stdio.h>

void swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void ShellSort01(int arr[],int n)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
        //插入排序,原本的插入排序是以1为间隔的，现在我们的插入排序是以gap为间隔的
        for(int i=gap;i<n;i++)
        {
            for(int j=i;j>0;j-=gap)
            {
                if(arr[j]<arr[j-gap])
                {
                    swap(&arr[j],&arr[j-gap]);
                }
            }
        }
    }
}

//对希尔增量进行优化
void ShellSort02(int arr[],int n)
{
    int h=1;
    while(h<=n/3)
    {
        h=h*3+1;//Kunth序列
    }
    for(int gap=h;gap>0;gap=(gap-1)/3)
    {
        for(int i=gap;i<n;i++)
        {
            for(int j=i;j>0;j-=gap)
            {
                if(arr[j]<arr[j-gap])
                {
                    swap(&arr[j],&arr[j-gap]);
                }
            }
        }
    }
}


void ShellSort03(int arr[],int n)
{
    int h=1;
    while(h<=n/3)
    {
        h=h*3+1;
    }
    for(int gap=h;gap>0;gap=(gap-1)/3)
    {
        for(int i=gap;i<n;i++)
        {
            int tmp=arr[i];
            int j=i;
            while(j>0&&arr[j-gap]>tmp)
            {
                arr[j]=arr[j-gap];
                j=j-gap;
            }
            arr[j]=tmp;
        }
    }
}

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
    ShellSort03(arr,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

