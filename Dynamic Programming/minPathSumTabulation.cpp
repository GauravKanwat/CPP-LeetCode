#include <bits/stdc++.h> 
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 and j == 0) dp[i][j] = grid[i][j];
            else {
                int left = grid[i][j], up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}

int main() {

    vector<vector<int>> grid = {{5,9,6}, {11,5,2}};
    cout << minSumPath(grid) << endl;
    return 0;
}