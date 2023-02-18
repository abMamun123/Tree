/**
 *author:xyz_123
 *created:15-02-2023(13:22:26)
 **/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *parent;
    Node *left;
    Node *right;
    int id;
};
class Binary_tree
{
public:
    Node *root;
    Binary_tree()
    {
        root = NULL;
    }
    // create new node dinamicaly
    Node *CreateNewNode(int id)
    {
        Node *newNode = new Node;
        newNode->id = id;
        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // build binary tree
    void buildBinaryTree()
    {
        Node *allNode[6];
        for (int i = 0; i < 6; i++)
        {
            allNode[i] = CreateNewNode(i);
        }
        root = allNode[0];
        allNode[0]->left = allNode[1];
        allNode[0]->right = allNode[2];
        allNode[1]->parent = allNode[0];
        allNode[1]->left = allNode[5];
        allNode[2]->parent = allNode[0];
        allNode[2]->left = allNode[3];
        allNode[2]->right = allNode[4];
        allNode[5]->parent = allNode[1];
        allNode[3]->parent = allNode[2];
        allNode[4]->parent = allNode[2];
    }
    // BFS
    void BFS()
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->left!=NULL){
                l = a->left->id;
                q.push(a->left);
            }
            if(a->right!=NULL){
                r = a->right->id;
                q.push(a->right);
            }
            if(a->parent!=NULL){
                p = a->parent->id;
            }
            cout<<"node "<<a->id<<" parent "<<p<<" left child "<<l<<" right child "<< r<<endl;
        }
    }
};
int main()
{
    Binary_tree bt;
    bt.buildBinaryTree();
    bt.BFS();
    return 0;
}