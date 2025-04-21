#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    vector<vector<int>> items;
    for (int i = 0; i < val.size(); i++)
    {
        items.push_back({val[i], wt[i]});
    }

    // Sort by value/weight ratio in descending order
    sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b)
         { return (double)a[0] / a[1] > (double)b[0] / b[1]; });

    double ans = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        int value = items[i][0];
        int weight = items[i][1];

        if (weight <= capacity)
        {
            ans += value;
            capacity -= weight;
        }
        else
        {
            ans += (double)value * capacity / weight;
            break;
        }
    }

    return round(ans * 1e6) / 1e6; // Rounded to 6 decimal places
}