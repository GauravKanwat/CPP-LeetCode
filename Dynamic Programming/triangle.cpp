#include <bits/stdc++.h> 
using namespace std;

int rec(int i, int j, int n, vector<vector<int>> triangle, vector<vector<int>> &dp) {
    if(i == n) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = 0, diag = 0;
    if(i < n) down = rec(i+1, j, n, triangle, dp);
    if(i < n and j < n) diag = rec(i+1, j+1, n, triangle, dp);
    return dp[i][j] = triangle[i][j] + min(down, diag);    
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return rec(0, 0, n-1, triangle, dp);
}

int main() {
    int n = 4;
    vector<vector<int>> triangle = {{1}, {2,3}, {3,6,7}, {8,9,6,1}};
    cout << minimumPathSum(triangle, n) << endl;
    return 0;
}