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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // using floyd's cycle detection algorithm
    // slow pointer moves one step at a time
    // fast pointer moves two steps at a time
    // if there is a cycle, they will meet at some point
    // if they meet, move slow pointer to head and move both pointers one step at a time
    // when they meet again, return the meeting point
    // if there is no cycle, return NULL
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}