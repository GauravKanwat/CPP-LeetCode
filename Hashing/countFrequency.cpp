#include<bits/stdc++.h>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums) {
    vector<int> mpp(n,0);
    for(int i=0; i<n; i++) {
        mpp[nums[i]-1]++;
    }
    return mpp;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    vector<int> result;
    result = countFrequency(n, 0, nums);
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}