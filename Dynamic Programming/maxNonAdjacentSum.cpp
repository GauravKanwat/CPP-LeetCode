#include<bits/stdc++.h>
using namespace std;

int rec(int n, vector<int> nums, vector<int> &dp) {
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    if(dp[n] != -1) return dp[n];
    int pick = nums[n] + rec(n-2, nums, dp);
    int notPick = 0 + rec(n-1, nums, dp);
    return dp[n] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return rec(n-1, nums, dp);
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums) << endl;
    return 0;
}