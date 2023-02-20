/**
 *author:Abu Jafar Shiddik
 *created:18-02-2023(11:44:07)
 **/
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
    int val;
    node *left;
    node *right;
    node *parent;
};
class Binary_TREE
{
public:
    node *root;
    Binary_TREE()
    {
        root = NULL;
    }
    // create new node
    node *create_new_node(int id, int val)
    {
        node *new_node = new node;
        new_node->id = id;
        new_node->val = val;
        new_node->right = NULL;
        new_node->left = NULL;
        new_node->parent = NULL;
        return new_node;
    }
    // insert
    void Insertion(int id, int val)
    {
        node *new_node = create_new_node(id, val);
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *a = q.front();
            q.pop();
            if (a->left != NULL)
            {
                q.push(a->left);
            }
            else
            {
                a->left = new_node;
                new_node->parent = a;
                return;
            }
            if (a->right != NULL)
            {
                q.push(a->right);
            }
            else
            {
                a->right = new_node;
                new_node->parent = a;
                return;
            }
        }
    }
    // inorder
    void in_order(node *a)
    {
        if (a == NULL)
            return;
        in_order(a->left);
        cout << a->val << " ";
        in_order(a->right);
    }
    // preorder
    void pre_order(node *a)
    {
        if (a == NULL)
            return;
        cout << a->val << " ";
        pre_order(a->left);
        pre_order(a->right);
    }
    // postorder
    void post_order(node *a)
    {
        if (a == NULL)
            return;
        post_order(a->left);
        post_order(a->right);
        cout << a->val << " ";
    }
};
int main()
{
    Binary_TREE bt;
    bt.Insertion(0, 20);
    bt.Insertion(1, 10);
    bt.Insertion(2, 22);
    bt.Insertion(3, 5);
    bt.Insertion(4, 12);
    bt.Insertion(5, 21);
    bt.Insertion(6, 25);
    bt.Insertion(7, 3);
    bt.Insertion(8, 15);
    cout << "inorder :";
    bt.in_order(bt.root);
    cout << endl;
    cout << "preorder :";
    bt.pre_order(bt.root);
    cout << endl;
    cout << "postorder :";
    bt.post_order(bt.root);
    cout << endl;
    return 0;
}