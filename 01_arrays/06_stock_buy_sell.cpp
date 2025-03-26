#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int mini = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - mini; // cost of selling on i and buying with mini
        profit = max(profit, cost);  // storing maximum profit
        mini = min(mini, prices[i]); // storing minimum value of mini before selling on next day to get max profit
    }
    return profit;
}