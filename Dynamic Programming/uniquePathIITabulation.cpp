#include<iostream>
using namespace std;


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 and j == 0) dp[i][j] = 1;
            else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{0,0,0}, {0,-1,0}, {0,0,0}};
    cout << mazeObstacles(n, m, matrix) << endl;
    return 0;
}