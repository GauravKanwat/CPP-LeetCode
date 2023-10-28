#include <bits/stdc++.h> 
using namespace std;

int rec(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(n == 0 and m == 0) return grid[0][0];
    if(n < 0 or m < 0) return INT_MAX;
    if(dp[n][m] != -1) return dp[n][m];
    int left = rec(n, m-1, grid, dp);
    int up = rec(n-1, m, grid, dp);
    return dp[n][m] = grid[n][m] + min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return rec(n-1, m-1, grid, dp);
}

int main() {

    vector<vector<int>> grid = {{5,9,6}, {11,5,2}};
    cout << minSumPath(grid) << endl;
    return 0;
}