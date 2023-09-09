#include<bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v) {
    unordered_map<int, int> mpp;
    for(auto i : v) {
        mpp[i]++;
    }
    int max = INT_MIN, min = INT_MAX;
    vector<int> ans(2);
    for(auto i : mpp) {
        if(i.second > max) {
            ans[0] = i.first;
            max = i.second;
        }
        if(i.second < min) {
            ans[1] = i.first;
            min = i.second;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0; i<n; i++) {
        cin >> inp[i];
    }
    vector<int> result;
    result = getFrequencies(inp);
    for(int i : result) cout << i << " ";
    cout << endl;
    return 0;
}