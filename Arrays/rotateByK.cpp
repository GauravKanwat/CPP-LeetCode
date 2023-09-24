#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    vector<int> tempArr;
    for(int i=0; i<k; i++) {
        tempArr.push_back(arr[i]);
    }
    int n = arr.size();
    for(int i=0; i<n-k; i++) {
        arr[i] = arr[i+k];
    }
    int j = 0;
    for(int i=n-k; i<n; i++) {
        arr[i] = tempArr[j];
        j++;
    }
    return arr;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    arr = rotateArray(arr, k);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}