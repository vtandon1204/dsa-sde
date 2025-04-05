#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    // set<int> st;
    // vector<int> ans;
    // for(int i=0;i<nums.size();i++){
    //     st.insert(nums[i]);
    // }
    // int index=0;
    // for(auto it:st){
    //     ans[index]=it;
    //     index++;
    // }
    // return index+1;

    // *********************************************************
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}