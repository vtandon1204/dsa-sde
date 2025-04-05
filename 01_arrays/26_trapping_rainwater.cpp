#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0; // Edge case

    vector<int> leftMax(n, 0), rightMax(n, 0);
    
    // Compute left max heights
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Compute right max heights
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Compute trapped water
    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        totalWater += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }

    return totalWater;
}