#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int j = arr[0];
    for(int i=0; i<n; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = j;
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vector<int> result = rotateArray(arr, n);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}