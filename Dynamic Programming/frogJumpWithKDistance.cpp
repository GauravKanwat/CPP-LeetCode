#include<iostream>
using namespace std;

int f(int n, int k, vector<int> &height, vector<int> &dp) {
    if(n<=0) return 0;
    if(dp[n] != -1) return dp[n];
    int minCost = INT_MAX;
    for(int i=1; i<=k; i++) {
        if(n-i >= 0) {
            minCost = min(minCost, f(n-i, k, height, dp) + abs(height[n] - height[n-i]));
        }
    }
    return dp[n] = minCost;
}

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n+1, -1);
    return f(n-1, k, height, dp);
}

int main()
{
    int n = 4, k = 2;
    vector<int> height = {10, 40, 30, 10};
    cout << minimizeCost(n, k, height) << endl;
    // minimizeCost(n, k, height);
    return 0;
}