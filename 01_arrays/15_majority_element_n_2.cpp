#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &v)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++) // counting the frequency of each element
    {
        mp[v[i]]++;
    }
    int n = v.size() / 2;
    for (auto it : mp) // iterating through the map to find the majority element
    // if the frequency of an element is greater than n/2, return that element
    {
        if (it.second > n)
            return it.first;
    }
    return -1; // if no majority element found
}