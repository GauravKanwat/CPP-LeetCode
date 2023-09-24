#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> a, int n) {
    int max = INT_MIN, smax = 0;
    for(int i=0; i<n; i++) {
        if(a[i] > max) {
            smax = max;
            max = a[i];
        }
        if(a[i] < max && a[i] > smax) {
            smax = a[i];
        }
    }
    return smax;
}

int secondSmallest(vector<int> a, int n) {
    int min = INT_MAX, smin = 0;
    for(int i=0; i<n; i++) {
        if(a[i] < min) {
            smin = min;
            min = a[i];
        }
        if(a[i] > min && a[i] < smin) {
            smin = a[i];
        }
    }
    return smin;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int sLargest = secondLargest(a, n);
    int sSmallest = secondSmallest(a, n);
    return {sLargest, sSmallest};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vector<int> result = getSecondOrderElements(n, arr);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}