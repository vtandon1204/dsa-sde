#include <bits/stdc++.h>
using namespace std;

void func(int ind, int target, vector<int> &temp, vector<vector<int>> &ans,
          vector<int> &candidates)
{
    int n = candidates.size();
    if (ind == n)
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (candidates[ind] <= target)
    {
        temp.push_back(candidates[ind]);
        func(ind, target - candidates[ind], temp, ans, candidates);
        temp.pop_back();
    }
    func(ind + 1, target, temp, ans, candidates);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    func(0, target, temp, ans, candidates);
    return ans;
}