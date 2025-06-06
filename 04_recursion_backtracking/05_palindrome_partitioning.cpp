#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int st, int e)
{
    while (st <= e)
    {
        if (s[st++] != s[e--]) // check characters from both ends of the string
            return false;
    }
    return true;
}

void func(string s, int ind, vector<string> &temp, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(temp); // if we have reached the end of the string, add the current partition to the answer
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i)) // check if the substring from index 'ind' to 'i' is a palindrome
        {
            temp.push_back(s.substr(ind, i - ind + 1)); // add the palindrome substring to the current partition
            // recursively call the function for the next index
            func(s, i + 1, temp, ans);
            temp.pop_back(); // backtrack by removing the last added substring
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    func(s, 0, temp, ans);
    return ans;
}