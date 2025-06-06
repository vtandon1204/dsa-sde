#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>> &graph, int N, int col, vector<int> &color)
{
    for (int i = 0; i < N; i++)
    {
        // Check if the node is adjacent and has the same color
        if (graph[node][i] && color[i] == col)
            return false;
    }
    return true; // Safe to color the node with col
}
bool solve(vector<vector<int>> &graph, int N, int M, int node, vector<int> &color)
{
    if (node == N)
        return true; // All nodes are colored

    for (int col = 1; col <= M; col++)
    {
        if (isSafe(node, graph, N, col, color))
        {
            color[node] = col; // Assign color to the node
            if (solve(graph, N, M, node + 1, color))
                return true;  // Recur for next node
            color[node] = -1; // Backtrack if not possible
        }
    }
    return false;
}
bool Mcoloring(vector<vector<int>> &graph, int N, int M)
{
    vector<int> color(N, -1);
    if (solve(graph, N, M, 0, color))
        return true;
    return false;
}