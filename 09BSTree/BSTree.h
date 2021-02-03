#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BTreeNode
{
    BTreeNode<K>* left;
    BTreeNode<K>* right;
    K _key;

    BTreeNode(const K& key)
        :left(nullptr)
        ,right(nullptr)
        ,_key(key)
    {

    }
};


template<class K>
class BSTree //Binary Search Tree
{
    typedef BTreeNode<K> Node;
public:
    bool Insert(const K& key)
    {
        if(_root==nullptr)
        {
            _root=new Node(key);
            return true;
        }
        Node* parent=nullptr;
        Node* cur=_root;
        while(cur)
        {
            if(cur->_key<key)
            {
                parent=cur;
                cur=cur->right;
            }
            else if(cur->_key>key)
            {
                parent=cur;
                cur=cur->left;
            }
            else
            {
                return false;
            }
        }
        cur=new Node(key);
        if(parent->_key<key)
        {
            parent->right=cur;
        }
        else
        {
            parent->left=cur;
        }
        return true;
    }

    Node* Find(const K& key)
    {
        Node* cur=_root;
        while(cur)
        {
            if(cur->_key<key)
            {
                cur=cur->right;
            }
            else if(cur->_key>key)
            {
                cur=cur->left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

    bool Erase(const K& key)
    {
        Node* parent=nullptr;
        Node* cur=_root;
        while(cur)
        {
            if(cur->_key<key)
            {
                parent=cur;
                cur=cur->right;
            }
            else if(cur->_key>key)
            {
                parent=cur;
                cur=cur->left;
            }
            else
            {
                //找到了，开始删除
                //1.左为空
                //2.右为空
                //3.左右都不为空
                if(cur->left==nullptr)
                {
                    //1.左为空的逻辑
                    if(parent==nullptr)
                    {
                        _root=cur->right;
                    }
                    else
                    {
                        //我是父亲的左，就让父亲的左指向我的右
                        if(cur==parent->left)
                            parent->left=cur->right;
                        else
                            parent->right=cur->right;
                    }
                    delete cur;
                }
                else if(cur->right==nullptr)
                {
                    if(parent==nullptr)
                    {
                       _root=cur->left; 
                    }
                    else
                    {
                        if(cur==parent->left)
                            parent->left=cur->left;
                        else
                            parent->right=cur->left;
                    }
                    delete cur;
                }
                else
                {
                    Node* rightMinParent=cur;
                    Node* rightMin=cur->right;
                    while(rightMin->left)
                    {
                        rightMinParent=rightMin;
                        rightMin=rightMin->left;
                    }
                    swap(cur->_key,rightMin->_key);
                    //转换成删除rightMin
                    if(rightMinParent->right==rightMin)
                        rightMinParent->right=rightMin->right;
                    else
                        rightMinParent->left=rightMin->right;
                    delete rightMin;

                }
                return true;
            }
        }
        return false;
    }
    void _Inorder(Node* root)
    {
        if(root==nullptr)
            return ;
        _Inorder(root->left);
        cout<<root->_key<<" ";
        _Inorder(root->right);
    }
    void Inorder()
    {
        _Inorder(_root);
        cout<<endl;
    }
private:
    Node* _root=nullptr;
};


void TestTree()
{
    BSTree<int> t;
    int a[]={5,3,4,1,7,8,2,6,0,9};
    for(auto e:a)
    {
         t.Insert(e);
    }
    t.Inorder();

    t.Erase(7);
    t.Inorder();
}

