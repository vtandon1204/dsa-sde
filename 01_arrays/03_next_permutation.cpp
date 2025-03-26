#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--) // find the break point where the value starts to decrease
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1) // if there's no such point, the next permutation is reverse of the array
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i >= ind + 1; i--)
    {
        if (arr[i] > arr[ind]) // the element which is greater than the break point element but still smallest among them
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
}