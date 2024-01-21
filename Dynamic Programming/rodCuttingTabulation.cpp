#include<iostream>
using namespace std;

int cutRod(vector<int> &price, int n) {
    int size = price.size();
    vector<vector<int>> dp(size, vector<int> (n+1, 0));
    
    for(int N = 0; N <= n; N++) {
        dp[0][N] = N * price[0];
    }
    
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << cutRod(arr, n) << endl;
    return 0;
}