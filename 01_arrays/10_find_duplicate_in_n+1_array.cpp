#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> num){
    // Method 1: Using Hashing
    int n = num.size();
    vector<int> freq(n+1,0);
    for(int i=0;i<num.size();i++){
        freq[num[i]]++;
        if(freq[num[i]]>1){
            return num[i];
        }
    }

    // Method 2: Using Floyd's Cycle Detection Algorithm / Linked List Cycle Method
    // This method is used when we have to find the duplicate element in an array where the elements 
    // of the array are in the range of 1 to n-1 and there is only one duplicate element.
    int slow = num[0];
    int fast = num[0];
    do{
        slow = num[slow];
        fast = num[num[fast]];
    }while(slow!=fast);
    fast = num[0];
    while(slow!=fast){
        slow = num[slow];
        fast = num[fast];
    }
    return slow;
}