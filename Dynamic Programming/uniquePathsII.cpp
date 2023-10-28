#include<iostream>
using namespace std;

int rec(int n, int m, vector<vector<int>> mat, vector<vector<int>> &dp) {
    if(n >= 0 and m >= 0 and mat[n][m] == -1) return 0;
    if(n == 0 and m == 0) return 1;
    if(n < 0 or m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    int left = rec(n, m-1, mat, dp);
    int up = rec(n-1, m, mat, dp);
    return dp[n][m] = left + up;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return rec(n-1, m-1, mat, dp);
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{0,0,0}, {0,-1,0}, {0,0,0}};
    cout << mazeObstacles(n, m, matrix) << endl;
    return 0;
}