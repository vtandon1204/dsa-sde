#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0, maxx = 0; // cnt is used to count the number of 1s in a row
    // maxx is used to store the maximum number of 1s in a row
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            // maxx = max(cnt, maxx);
        }
        else
        {
            maxx = max(cnt, maxx);
            cnt = 0;
        }
    }
    maxx = max(cnt, maxx);
    return maxx;
}