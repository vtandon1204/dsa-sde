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

int length(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    cout << len << endl;
    return len;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // if k is 0 or k is equal to the length of the list, return the head

    // find the kth node from the end of the list that will be the new head
    int len = length(head);
    k = k % len;
    int pos = len - k;
    ListNode *temp = head;
    while (pos - 1)
    {
        temp = temp->next;
        pos--;
    }

    // temp is now at the kth node from the end of the list
    ListNode *curr = head;
    if (temp->next)
    {
        ListNode *next = temp->next;
        head = next;
        temp->next = NULL;
        while (next->next)
        {
            next = next->next;
        }
        next->next = curr;
    }
    return head;
}