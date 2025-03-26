#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i]; // add every element to the sum
        max_sum = max(max_sum, sum); // store the maximum value of sum till now
        if (sum < 0) // if at any moment the sum gets negative, initialize it with 0
        {
            sum = 0;
        }
    }
    return max_sum;
}