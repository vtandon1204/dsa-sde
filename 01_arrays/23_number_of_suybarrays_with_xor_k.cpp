#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;      // Initialize the map with 0 XOR count as 1
    int preXOR = 0; // Variable to store the prefix XOR
    int cnt = 0;    // Counter for the number of subarrays with XOR equal to k

    for (int i = 0; i < nums.size(); i++)
    {
        preXOR ^= nums[i]; // Calculate the prefix XOR

        // Check if there exists a prefix XOR that when XORed with current prefix gives k
        if (mp.find(preXOR ^ k) != mp.end())
        {
            cnt += mp[preXOR ^ k]; // Increment count by the number of such prefixes
        }

        mp[preXOR] += 1; // Update the map with the current prefix XOR count
    }
    return cnt; // Return the total count of subarrays with XOR equal to k
}