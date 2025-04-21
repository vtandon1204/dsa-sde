#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &Arrival, vector<int> &Departure)
{
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxCnt = 0;
    while (i < Arrival.size())
    {
        if (Arrival[i] <= Departure[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}