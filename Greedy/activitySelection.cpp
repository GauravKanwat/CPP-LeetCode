#include<bits/stdc++.h>
using namespace std;

bool sortIt(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n)
        {
        // Your code here
        vector<pair<int, int>> activity;
        for(int i=0; i<n; i++) {
            activity.push_back({start[i], end[i]});
        }
        sort(activity.begin(), activity.end(), sortIt);
        
        int active = 1;
        int prev = 0;
        for(int i=1; i<n; i++) {
            if(activity[i].first > activity[prev].second) {
                active++;
                prev = i;
            }
        }
        return active;
    }

int main()
{
    vector<int> start = {1,3,2,5};
    vector<int> end = {2,4,3,6};
    int n = 4;
    cout << activitySelection(start, end, n) << endl;
    return 0;
}