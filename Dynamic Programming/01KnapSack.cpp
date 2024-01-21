#include<bits/stdc++.h>
using namespace std;

int rec(int index, int maxWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp) {
    if(index == 0) {
        if(maxWeight >= weight[0]) return value[0];
        else return 0;
    }
    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
    int notTake = 0 + rec(index - 1, maxWeight, weight, value, dp);
    int take = INT_MIN;
    if(maxWeight >= weight[index]) {
        take = value[index] + rec(index - 1, maxWeight - weight[index], weight, value, dp);
    }
    return dp[index][maxWeight] = max(notTake, take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
    return rec(n-1, maxWeight, weight, value, dp);
}

int main() {
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4;
    int maxWeight = 5;
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}