#include <bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int maxJobs = 0;
    int maxProfit = 0;

    vector<vector<int>> jobs;
    for (int i = 0; i < deadline.size(); i++)
    {
        jobs.push_back({profit[i], deadline[i]});
    }

    sort(jobs.begin(), jobs.end(), greater<vector<int>>()); // Sort jobs by profit in descending order

    int maxDeadline = *max_element(deadline.begin(), deadline.end());
    vector<int> slots(maxDeadline + 1, -1); // Initialize slots to -1 (unoccupied)

    for (int i = 0; i < profit.size(); i++)
    {
        for (int j = jobs[i][1]; j > 0; j--)
        {
            if (slots[j] == -1)
            {                            // If the slot is unoccupied
                slots[j] = i;            // Assign the job to this slot
                maxJobs++;               // Increment the count of jobs
                maxProfit += jobs[i][0]; // Add the profit of this job
                break;                   // Break out of the loop as we have assigned this job
            }
        }
    }
    // maxJobs = count of jobs assigned
    // maxProfit = total profit from assigned jobs
    // slots = array of assigned jobs (not needed in the final output)
    return {maxJobs, maxProfit};
}