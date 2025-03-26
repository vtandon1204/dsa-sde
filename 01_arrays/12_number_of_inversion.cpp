#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void merge(vector<int> arr, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            cnt += (m - i + 1);
        }
    }
    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= r)
    {
        temp.push_back(arr[j++]);
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(vector<int> arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
int inversionCount(vector<int> arr, int n)
{
    mergeSort(arr, 0, n - 1);
    return cnt;
}