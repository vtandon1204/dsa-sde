#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    int sum = 0;
    int k=0;
    map<int,int> preSum;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum==k) maxLen = max(maxLen, i+1);
        int rem = sum-k;
        
        if(preSum.find(rem)!=preSum.end()){
            int len = i-preSum[rem];
            maxLen = max(len,maxLen);
        }
        
        if(preSum.find(sum)==preSum.end()){
            preSum[sum] = i;
        }
    }
    return maxLen;
    
}