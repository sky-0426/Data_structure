#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
//结点结构
typedef struct BinartTreeNode
{
    DataType data;
    struct BinartTreeNode* left;
    struct BinartTreeNode* right;
}BTNode;

//通过前序遍历的数组“ABD##E#H##CF##G##”构建二叉树
BTNode* BinartTreeCreate(DataType* a,int n,int* p)
{
    //判断当前节点是否为空
    if(a[*p]=='#'||*p>=n)
    {
        //结点为空，则返回NULL
        (*p)++;
        return NULL;
    }
    //当前结点非空，创建新结点
    BTNode* root=(BTNode*)malloc(sizeof(BTNode));
    root->data=a[*p];
    //字符向后移动一个位置
    (*p)++;
    //创建左子树
    root->left=BinartTreeCreate(a,n,p);
    //创建右子树
    root->right=BinartTreeCreate(a,n,p);
    return root;
}

//二叉树的销毁
void BinartTreeDestory(BTNode** root)
{
    //如果二叉树不为空
    if(root)
    {
        //销毁左子树
        BinartTreeDestory(&(*root)->left);
        //销毁右子树
        BinartTreeDestory(&(*root)->right);
        //释放节点
        free(*root);
        //置空
        *root=NULL;
    }
}

//二叉树节点的个数
int BinaryTreeSize(BTNode* root)
{
    //当前节点为空，返回0
    if(root==NULL)
    {
        return 0;
    }
    //计算左子树结点个数
    int leftnum=BinaryTreeSize(root->left);
    //计算右子树结点个数
    int rightnum=BinaryTreeSize(root->right);
    //左子树结点个数+右子树结点个数+1
    int ret=leftnum+rightnum+1;
    return ret;
}

//二叉树叶子结点个数
int BinartTreeLeafSize(BTNode* root)
{
    //当树为空时，叶子结点个数为0
    //当某个结点的左右子树均为空时，此结点就是叶子结点，返回1
    int count=0;
    if(!root)
    {
        return 0;
    }
    else if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    else
    {
        count=BinartTreeLeafSize(root->left)+BinartTreeLeafSize(root->right);
    }
    return count;
}

//二叉树第K层结点的个数
int BinaryTreeLevelKSize(BTNode* root,int k)
{
    //树为空或者k小于等于0.返回0
    if(root==NULL||k<=0)
    {
        return 0;
    }
    //树不为空且k等于1，返回1
    if(root!=NULL&&k==1)
    {
        return 1;
    }
    return BinaryTreeLevelKSize(root->left,k-1)+BinaryTreeLevelKSize(root->right,k-1);
}

//查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root,DataType x)
{
    if(!root)
    {
        return NULL;
    }
    if(root->data==x)
    {
        return root;
    }
    //当前节点不为空也不等于x,遍历左子树
    BTNode* tmp=BinaryTreeFind(root->left,x);
    if(!tmp)
    {
        return tmp;
    }
    else
    {
        return tmp=BinaryTreeFind(root->right,x);
    }
}

//二叉树的前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
    if(root)
    {
        putchar(root->data);
        BinaryTreePrevOrder(root->left);
        BinaryTreePrevOrder(root->right);
    }
}

//二叉树的中序遍历
void BinaryTreeInOrder(BTNode* root)
{
    if(root)
    {
        BinaryTreeInOrder(root->left);
        putchar(root->data);
        BinaryTreeInOrder(root->right);
    }
}

//二叉树的后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if(root)
    {
        BinaryTreePostOrder(root->left);
        BinaryTreePostOrder(root->right);
        putchar(root->data);
    }
}
