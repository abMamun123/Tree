/**
 *author:Abu Jafar Shiddik
 *created:16-02-2023(17:20:36)
 **/
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    // create_new_node
    node *create_new_node(int val)
    {
        node *new_node = new node;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->data = val;
        return new_node;
    }

    // Insertion in BST
    void Insert(int val)
    {
        node *new_node = create_new_node(val);
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if (new_node->data > cur->data)
            {
                prv = cur;
                cur = cur->right;
            }
            else
            {
                prv = cur;
                cur = cur->left;
            }
        }
        if (new_node->data > prv->data)
            prv->right = new_node;
        else
            prv->left = new_node;
    }
    // search value in BST
    bool Search(int val)
    {
        node *cur = root;
        while (cur != NULL)
        {
            if (val > cur->data)
                cur = cur->right;
            else if (val < cur->data)
                cur = cur->left;
            else
                return true;
        }
        return false;
    }
};
int main()
{ BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);
    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //1
    cout<<bst.Search(60)<<"\n"; //0
    return 0;
}