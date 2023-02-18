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
    Node *allNode[6];
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

    // print binary tree
    void printTreesInfo()
    {
        for (int i = 0; i < 6; i++)
        {
            int p = -1;
            int l = -1;
            int r = -1;
            if (allNode[i]->parent != NULL){
                p = allNode[i]->parent->id;
            }
             if (allNode[i]->left != NULL){
                l = allNode[i]->left->id;
            }
            if (allNode[i]->right != NULL){
                r = allNode[i]->right->id;
            }
            cout<<"node "<< i <<" parent  "<< p <<" left "<< l <<" right "<< r<<"\n";
        }
    }
};
int main()
{
    Binary_tree bt;
    bt.buildBinaryTree();
    bt.printTreesInfo();
    return 0;
}