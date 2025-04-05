#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        // remove any dupicates
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0) // sum is zero, so we found the triplet
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                // Skip duplicates
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
            else if (sum < 0) // sum is less than 0, so we need to increase the sum
            {
                j++;
            }
            else // sum is greater than 0, so we need to decrease the sum
            {
                k--;
            }
        }
    }
    return ans;
}