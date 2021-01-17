#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0;
    char str[]={"ABD##E#H##CF##G##"};
    int n=strlen(str);
    //二叉树节点个数
    BTNode* tree=BinartTreeCreate(str,n,&i);
    printf("结点个数%d\n",BinaryTreeSize(tree));

    
    //前序
    printf("前序:");
    BinaryTreePrevOrder(tree);
    printf("\n");

    //中序
    printf("中序:");
    BinaryTreeInOrder(tree);
    printf("\n");
    

    //后序
    printf("后序:");
    BinaryTreePostOrder(tree);
    printf("\n");
    
    
    printf("叶子结点个数%d\n",BinartTreeLeafSize(tree));

    return 0;
}

