#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a && b)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}
Node *flatten(Node *root)
{
    if (!root || !root->next)
        return root;

    // recursively flatten the list:
    // flatten the next list:
    root->next = flatten(root->next);
    
    // merge the current list with the next list:
    root = mergeTwoLists(root, root->next);

    return root;
}