#include <bits/stdc++.h> 
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// Write your code here.
    vector<int> prev(n, 0);
    for(int j=0; j<n; j++) {
        prev[j] = triangle[n-1][j];
    }

    for(int i=n-2; i>=0; i--) {
        vector<int> curr(n, 0);
        for(int j=i; j>=0; j--) {
            int down = triangle[i][j] + prev[j];
            int diag = triangle[i][j] + prev[j+1];
            curr[j] = min(down, diag);
        }
        prev = curr;
    }
    return prev[0];
}

int main() {
    int n = 4;
    vector<vector<int>> triangle = {{1}, {2,3}, {3,6,7}, {8,9,6,1}};
    cout << minimumPathSum(triangle, n) << endl;
    return 0;
}