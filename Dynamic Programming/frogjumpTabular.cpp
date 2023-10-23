#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4, };
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int first = dp[i-1] + fabs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i > 1) second = dp[i-2] + fabs(heights[i] - heights[i-2]);

        dp[i] = min(first, second);
    }
    cout << dp[n-1] << endl;
    return 0;
}