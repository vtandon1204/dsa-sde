#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> hash(256, -1); // hash table to store the last index of each character
    int maxLength = 0;         // variable to store the maximum length of substring
    int n = s.length();

    int l = 0;
    int r = 0;
    while (r < n)
    {
        if (hash[s[r]] != -1)
        {
            l = max(l, hash[s[r] + 1]);
        }
        int len = r - l + 1;
        maxLength = max(maxLength, len);
        hash[s[r]] = r; // update the last index of the character
        r++;
    }
    return maxLength;
}