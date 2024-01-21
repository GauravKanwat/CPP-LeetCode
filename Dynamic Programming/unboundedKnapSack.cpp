#include<bits/stdc++.h>
using namespace std;

int rec(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if(index == 0) {
        return profit[0] * (w / weight[0]);
    }
    if(dp[index][w] != -1) return dp[index][w];
    int notTake = 0 + rec(index - 1, w, profit, weight, dp);
    int take = INT_MIN;
    if(w >= weight[index]) {
        take = profit[index] + rec(index, w - weight[index], profit, weight, dp);
    }
    return dp[index][w] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return rec(n-1, w, profit, weight, dp);
}

int main()
{
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};
    int n = 3, w = 10;
    cout << unboundedKnapsack(n, w, profit, weight) << endl;
    return 0;
}