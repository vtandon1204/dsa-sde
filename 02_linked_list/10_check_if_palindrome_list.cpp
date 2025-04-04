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
ListNode *reverse(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *newHead = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode *head)
{
    // // using stack (lifo)
    // stack<int> st;

    // // push all the elements of the list into the stack
    // ListNode *temp = head;
    // while (temp)
    // {
    //     st.push(temp->val);
    //     temp = temp->next;
    // }
    // temp = head;

    // // pop all the elements of the stack and compare with the list
    // // if they are not equal, return false
    // // if they are equal, continue
    // // if the stack is empty, return true
    // while (!st.empty())
    // {
    //     if (temp->val != st.top())
    //         return false;
    //     else
    //     {
    //         st.pop();
    //         temp = temp->next;
    //     }
    // }

    if (!head || !head->next)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is now at the middle of the list
    // reverse the second half of the list
    // and compare it with the first half of the list
    // if they are equal, return true
    // if they are not equal, return false
    ListNode *rev = reverse(slow->next);
    ListNode *first = head;
    ListNode *second = rev;
    while (second)
    {
        if (first->val != second->val)
        {
            reverse(rev);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(rev);
    return true;
}