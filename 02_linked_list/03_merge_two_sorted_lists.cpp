#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // If one of the lists is empty, return the other list
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode dummy(-1);  // Dummy node to simplify merging
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part of the non-empty list
    tail->next = (list1) ? list1 : list2;

    return dummy.next;  // The merged list starts from dummy.next
}