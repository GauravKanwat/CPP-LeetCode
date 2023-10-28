#include<iostream>
using namespace std;

long long int rec(int n, vector<int> valueInHouse, vector<int> &dp) {
    if(n == 0) return valueInHouse[0];
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    int take = valueInHouse[n] + rec(n-2, valueInHouse, dp);
    int notTake = 0 + rec(n-1, valueInHouse, dp);
    return dp[n] = max(take, notTake);
}

long long int houseRobber(vector<int>& valueInHouse) {
    // Write your code here.
    int n = valueInHouse.size();
    vector<int> temp1, temp2;
    if(n == 1) return n;
    for(int i=0; i<n; i++) {
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    vector<int> dp(n+1, -1);
    return max(rec(n-1, temp1, dp), rec(n-1, temp2, dp));
}

int main()
{
    vector<int> houses = {59, 53, 41, 26, 17, 13, 11};
    cout << houseRobber(houses) << endl;
    return 0;
}