#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void merge(vector<int> &arr, int l, int r, int m)
{
    vector<int> temp;
    int i = l;
    int j = m + 1;
    while (i <= m)
    {
        while (j <= r && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }
        cnt += (j - (m + 1));
        i++;
    }
    i = l;
    j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] > arr[j])
            temp.push_back(arr[j++]);
        else
            temp.push_back(arr[i++]);
    }
    while (i <= m)
        temp.push_back(arr[i++]);
    while (j <= r)
        temp.push_back(arr[j++]);
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, r, m);
}
int reversePairs(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return cnt;
}