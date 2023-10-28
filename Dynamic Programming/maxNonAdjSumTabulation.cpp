#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> nums = {2, 1, 4, 9};
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    int neg = 0;
    int take = 0, notTake = 0;
    for(int i=0; i<n; i++) {
        take = nums[i];
        if(i > 1) take += dp[i-2];
        notTake = dp[i-1];
        dp[i] = max(take, notTake);
    }
    cout << dp[n-1] << endl;
    return 0;
}