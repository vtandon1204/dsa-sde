#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;
    // All 0's --> 0 to i-1
    // All 1's --> i to j
    // All 2's --> j+1 to nums.size()-1

    for (int k = 0; k <= j;)
    {
        if (nums[k] == 0)
            swap(nums[i++], nums[k++]);
        else if (nums[k] == 1)
            k++;
        else if (nums[k] == 2)
            swap(nums[k], nums[j--]);
    }
}