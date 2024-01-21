#include<iostream>
using namespace std;

int rec(int index, vector<int>&price, int N, vector<vector<int>> &dp) {
    if(index == 0) {
        return N * price[0];
    }
    if(dp[index][N] != -1) return dp[index][N];
    int notTake = 0 + rec(index - 1, price, N, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= N) {
        take = price[index] + rec(index, price, N - rodLength, dp);
    }
    return dp[index][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n) {
    int size = price.size();
    vector<vector<int>> dp(size, vector<int> (n+1, -1));
    return rec(size - 1, price, n, dp);
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << cutRod(arr, n) << endl;
    return 0;
}