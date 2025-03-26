#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergerInterval(vector<vector<int>>intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    vector<int> currInterval = intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(currInterval[1]>=intervals[i][0]){
            currInterval[1] = max(currInterval[1], intervals[i][1]);
        }
        else{
            result.push_back(currInterval);
            currInterval = intervals[i];
        }
    }
    result.push_back(currInterval);
    return result;
}