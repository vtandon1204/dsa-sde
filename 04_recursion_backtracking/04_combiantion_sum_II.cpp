#include <bits/stdc++.h>
using namespace std;

void func(int ind, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > target)
            continue; // Skip if the current element is greater than the target
        if (i > ind && arr[i] == arr[i - 1])
            continue; // Skip duplicates
        temp.push_back(arr[i]);
        func(i + 1, target - arr[i], temp, ans, arr); // Move to the next index
        temp.pop_back();                              // Backtrack
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // Sort the array to handle duplicates
    vector<vector<int>> ans;
    vector<int> temp;
    func(0, target, temp, ans, candidates);
    return ans;
}