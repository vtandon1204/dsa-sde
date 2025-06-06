#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
            break;
        k = k % fact;
        fact = fact / nums.size();
    }
    return ans;
}