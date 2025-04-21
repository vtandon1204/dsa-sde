#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int g_ind = 0;
    int s_ind = 0;

    while (g_ind < g.size() && s_ind < s.size())
    {
        if (g[g_ind] <= s[s_ind])
        {
            g_ind++;
        }
        s_ind++;
    }
    return g_ind;
}