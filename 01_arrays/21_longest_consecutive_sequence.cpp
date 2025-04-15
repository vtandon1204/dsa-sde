#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int ans = 1;
    unordered_set<int> st; // stores only unique values
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    // for(auto it:st) cout<<it<<" ";
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end()) // check if 'it' is the starting number of a sequence
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) // check if next number in sequence is present in the set
            {
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}