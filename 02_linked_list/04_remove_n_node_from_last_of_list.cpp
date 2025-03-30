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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    int pos = len - n + 1;

    if (pos == 1)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (pos - 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        if (curr->next == NULL)
        {
            prev->next = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
    return head;
}