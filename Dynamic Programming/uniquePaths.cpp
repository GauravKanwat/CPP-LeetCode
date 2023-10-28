#include <bits/stdc++.h> 
using namespace std;

int rec(int m, int n, vector<vector<int>> &dp) {
    if(m == 0 and n == 0) return 1;
    if(m < 0 or n < 0) return 0;
    if(dp[m][n] != -1) return dp[m][n];
    int right = rec(m, n-1, dp);
    int down = rec(m-1, n, dp);
    return dp[m][n] = right + down;
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m-1, n-1, dp);
}

int main() {
    int m = 3, n = 2;
    cout << uniquePaths(m, n) << endl;
    return 0;
}