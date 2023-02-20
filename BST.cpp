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
    // BFS for traverse
    void BFS()
    {
        if (root == NULL)
            return;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *a = q.front();
            q.pop();
            int l = -1, r = -1;
            if (a->left != NULL)
            {
                l = a->left->data;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->data;
                q.push(a->right);
            }
            cout << "node value " << a->data << " left child " << l << " right child " << r << "\n";
        }
    }
    // Insertion in BST
    void insert(int val)
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
    bool search(int val)
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
    // delete node
    void Delete(int val)
    {
        node *cur = root;
        node *prev = NULL;
        while (cur != NULL)
        {
            if (val > cur->data)
            {
                prev = cur;
                cur = cur->right;
            }
            else if (val < cur->data)
            {
                prev = cur;
                cur = cur->left;
            }
            else
            {
                break;
            }
        }
        if (cur == NULL)
        {
            cout << "value is not present in bst\n";
            return;
        }
        // case-1 both left and right null
        if (cur->left == NULL && cur->right == NULL)
        {
            if (prev->left != NULL && prev->left->data == cur->data)
            {
                prev->left = NULL;
            }
            else
            {
                prev->right = NULL;
            }
            delete cur;
            return;
        }
        // case: 2 one side null
        if(cur->left!=NULL and cur->right == NULL){
            if(prev->left!=NULL and prev->left->data == cur->data){
                prev->left = cur->left;
            }
            else{
                prev->right = cur->left;
            }
            delete cur;
            return;
        }
         if(cur->left==NULL and cur->right != NULL){
            if(prev->left!=NULL and prev->left->data == cur->data){
                prev->left = cur->right;
            }
            else{
                prev->right = cur->right;
            }
            delete cur;
            return;
        }
        // case:3 both side have child
        node *temp = cur->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        int saved = temp->data;
        Delete(saved);
        cur->data = saved;
    }
};
int main()
{
    BST bst;
    bst.insert(8);
    bst.insert(7);
    bst.insert(12);
    bst.insert(5);
    bst.insert(9);
    bst.insert(11);
    bst.insert(13);
    bst.insert(10);
    bst.insert(5);
    cout << endl;
    bst.Delete(7);
    bst.BFS();
    return 0;
}