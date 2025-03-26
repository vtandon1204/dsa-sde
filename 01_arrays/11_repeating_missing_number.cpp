#include <bits/stdc++.h>
using namespace std;

vector<int> findRepeatingMissingNumbers(vector<int> &arr)
{
    int n = arr.size();
    int Sn = (n * (n + 1)) / 2;
    int S2n = (n * (2 * n + 1) * (n + 1)) / 6;
    int S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += arr[i] * arr[i];
    }
    int val1 = Sn - S; // repeat - miss
    int val2 = S2n - S2;
    val2 = val2 / val1; // repeat + miss
    int repeat = (val1 + val2) / 2;
    int miss = repeat - val1;
    return {repeat, miss};
}