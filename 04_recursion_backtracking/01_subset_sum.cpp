#include <bits/stdc++.h>
using namespace std;

void func(int i, int sum, vector<int> &arr, vector<int> &ans)
{
    if (i == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    // pick the element
    func(i + 1, sum + arr[i], arr, ans);
    // not pick the element
    func(i + 1, sum, arr, ans);
}
vector<int> subsetSum(vector<int> arr, int n)
{
    vector<int> ans;
    func(0, 0, arr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}