#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int sum)
{
    // int n = coins.size();

    // sort(coins.begin(), coins.end(), greater<int>()); // Sort coins in descending order
    // int ans = 0; // Initialize the answer to 0
    // for (int i = 0; i < n; i++) {
    //     if (sum == 0) break; // If sum is 0, break the loop
    //     ans += sum / coins[i]; // Add the number of coins of the current denomination to the answer
    //     sum %= coins[i]; // Update the remaining sum
    // }
    // return ans; // Return the total number of coins used

    vector<int> dp(sum + 1, INT_MAX); // Initialize dp array with maximum values
    dp[0] = 0;                        // Base case: 0 coins needed to make sum 0

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1); // Update dp[i] with the minimum number of coins needed
            }
        }
    }
    return dp[sum] == INT_MAX ? -1 : dp[sum]; // Return -1 if no solution found, else return the answer
}