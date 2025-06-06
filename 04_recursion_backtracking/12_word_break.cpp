#include <bits/stdc++.h>
using namespace std;

// *************************************************************************************
// Recursive solution
bool solve(int start, const string &s, const unordered_set<string> &wordSet)
{
    if (start == s.length()) // Base case: if we have reached the end of the string
        return true;

    for (int end = start + 1; end <= s.length(); ++end) // Try every possible end index for the substring
    {
        string word = s.substr(start, end - start);        // Extract the substring from start to end
        if (wordSet.count(word) && solve(end, s, wordSet)) // If the substring is in the word set and the rest of the string can be segmented recursively
        {
            return true;
        }
    }
    return false; // If no valid segmentation is found, return false
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Convert the vector to a set for O(1) lookups
    return solve(0, s, wordSet);
}


// *************************************************************************************

// Memoization
bool solve(int start, const string &s,
           const unordered_set<string> &wordSet, unordered_map<int, bool> &memo)
{
    if (start == s.length())
        return true;

    if (memo.count(start))
        return memo[start];
    for (int end = start + 1; end <= s.length(); ++end)
    {
        string word = s.substr(start, end - start);
        if (wordSet.count(word) && solve(end, s, wordSet, memo))
        {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    unordered_map<int, bool> memo;
    return solve(0, s, wordSet, memo);
}