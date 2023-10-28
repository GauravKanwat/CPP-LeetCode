#include<iostream>
using namespace std;

class Solution {
public:
    int rec(int n, vector<int> &dp) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int left = rec(n-1, dp);
        int right = 0;
        if(n > 1) right = rec(n-2, dp);
        return dp[n] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};

int main()
{
    int n = 2;
    Solution S;
    cout << S.climbStairs(n) << endl;
    return 0;
}