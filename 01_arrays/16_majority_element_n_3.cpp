#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) // counting the frequency of each element
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto it : mp) // iterating through the map to find the majority elements
    // if the frequency of an element is greater than n/3, add that element to the answer vector
    {
        if (it.second > (nums.size() / 3))
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}