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
    int val;
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
    Node *CreateNewNode(int id, int val)
    {
        Node *newNode = new Node;
        newNode->id = id;
        newNode->val = val;
        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
     // insert in tree
    void insert(int id, int val)
    {
        Node *newNode = CreateNewNode(id, val);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *a = q.front();
            q.pop();
            if (a->left != NULL)
                q.push(a->left);
            else
            {
                a->left = newNode;
                newNode->parent = a;
                return;
            }
            if (a->right != NULL)
                q.push(a->left);
            else
            {
                a->right = newNode;
                newNode->parent = a;
                return;
            }
        }
    };
    // build binary tree manually
    // void buildBinaryTree()
    // {
    //     Node *allNode[6];
    //     for (int i = 0; i < 6; i++)
    //     {
    //         allNode[i] = CreateNewNode(i);
    //     }
    //     root = allNode[0];
    //     allNode[0]->left = allNode[1];
    //     allNode[0]->right = allNode[2];
    //     allNode[1]->parent = allNode[0];
    //     allNode[1]->left = allNode[5];
    //     allNode[2]->parent = allNode[0];
    //     allNode[2]->left = allNode[3];
    //     allNode[2]->right = allNode[4];
    //     allNode[5]->parent = allNode[1];
    //     allNode[3]->parent = allNode[2];
    //     allNode[4]->parent = allNode[2];
    // }
    // BFS
    void BFS()
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if (a->left != NULL)
            {
                l = a->left->id;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->id;
                q.push(a->right);
            }
            if (a->parent != NULL)
            {
                p = a->parent->id;
            }
            cout << "node " << a->val << " parent " << p << " left child " << l << " right child " << r << endl;
        }
    }
    // DFS
    void DFS(Node *a)
    {
        if (a == NULL)
            return;
        cout << a->id << " ";
        DFS(a->left);
        DFS(a->right);
    }
    // inorder
    void Inorder(Node *a)
    {
        if (a == NULL)
            return;
        Inorder(a->left);
        cout << a->val << " ";
        Inorder(a->right);
    }
    // Preorder
    void Preorder(Node *a)
    {
        if (a == NULL)
            return;
        cout << a->val << " ";
        Preorder(a->left);
        Preorder(a->right);
    }
    // Postorder
    void Postorder(Node *a)
    {
        if (a == NULL)
            return;
        Postorder(a->left);
        Postorder(a->right);
        cout << a->val << " ";
    }
   
    // search
    void search(Node *a, int val)
    {
        if (a == NULL)
            return;
        if (a->val == val)
            cout << val << " found in node " << a->id << " "<<endl;
        search(a->left, val);
        search(a->right, val);
    };
};
int main()
{
    Binary_tree bt;
    // bt.buildBinaryTree();
    bt.insert(0, 1);
    bt.insert(1, 2);
    bt.insert(2, 3);
    bt.insert(3, 7);
    bt.insert(4, 9);
    bt.insert(5, 6);
    bt.insert(6, 4);
    bt.insert(7, 10);
    bt.insert(8, 12);
    bt.Inorder(bt.root);
    cout << "\n";
    bt.Preorder(bt.root);
    cout << "\n";
    bt.Postorder(bt.root);
    cout << "\n";
    bt.BFS();
    cout << "\n";
    // bt.search(bt.root, 10);
    return 0;
}