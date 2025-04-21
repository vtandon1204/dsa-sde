#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int, int>> time;

    for (int i = 0; i < end.size(); i++)
    {
        time.push_back({start[i], end[i]});
    }

    sort(time.begin(), time.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second < b.second; // Sort by end time
         });

    int cnt = 1;
    int endTime = time[0].second; // Initialize end time with the first meeting's end time
    for (int i = 1; i < time.size(); i++)
    {
        if (time[i].first > endTime)
        {                             // If the start time of the current meeting is greater than the end time of the last selected meeting
            cnt++;                    // Increment count of meetings
            endTime = time[i].second; // Update end time to the current meeting's end time
        }
    }
    return cnt; // Return the total count of meetings that can be attended
}