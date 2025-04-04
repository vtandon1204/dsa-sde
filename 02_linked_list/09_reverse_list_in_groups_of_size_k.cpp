#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *temp)
{
    ListNode *curr = temp;
    ListNode *prev = NULL;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *getKNode(ListNode *node, int k)
{
    k -= 1;
    while (node && k > 0)
    {
        k--;
        node = node->next;
    }
    return node;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevNode = NULL;
    while (temp)
    {
        ListNode *kNode = getKNode(temp, k);
        if (!kNode)
        {
            if (prevNode)
            {
                prevNode->next = temp;
            }
            break;
        }
        ListNode *nextNode = kNode->next;
        kNode->next = NULL;
        reverse(temp);
        if (temp == head)
        {
            head = kNode;
        }
        else
        {
            prevNode->next = kNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}