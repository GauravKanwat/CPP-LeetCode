#include<iostream>
using namespace std;

int rec(int day, int last, vector<vector<int>> points, vector<vector<int>> &dp) {
    if(day == 0) {
        int maxi = INT_MIN;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];
    int maxi = INT_MIN;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + rec(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return rec(n-1, 3, points, dp);
}

int main()
{
    vector<vector<int>> points = {{1,2,5}, {3,1,1}, {3,3,3}};
    int n = points.size();
    cout << ninjaTraining(n, points) << endl;
    return 0;
}