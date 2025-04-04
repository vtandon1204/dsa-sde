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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = 0;
    int len2 = 0;
    ListNode *tempA = headA;
    ListNode *tempB = headB;

    // calculate the length of both lists
    while (tempA)
    {
        len1++;
        tempA = tempA->next;
    }
    while (tempB)
    {
        len2++;
        tempB = tempB->next;
    }
    tempA = headA;
    tempB = headB;
    int cnt = 0;

    // move the pointer of the longer list by the difference of lengths
    // so that both pointers are at the same distance from the end of the list
    if (len1 >= len2)
    {
        cnt = len1 - len2;
        while (cnt)
        {
            tempA = tempA->next;
            cnt--;
        }
    }
    else
    {
        cnt = len2 - len1;
        while (cnt)
        {
            tempB = tempB->next;
            cnt--;
        }
    }

    // now move both pointers at the same pace until they meet
    // or one of them reaches the end of the list
    // if they meet, return the intersection point
    // if one of them reaches the end of the list, return NULL
    while (tempA && tempB)
    {
        if (tempA == tempB)
        {
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}