#include<bits/stdc++.h>
#include<vector>
using namespace std;

// int getSingleElement(vector<int> &arr){
// 	// Write your code here.	
//     int n = arr.size();
//     for(int i=0; i<n; i++) {
//         int count = 0;
//         for(int j=0; j<n; j++) {
//             if(arr[i] == arr[j]) count++;
//         }
//         if(count == 1) return arr[i];
//     }
//     return 0;
// }

// int getSingleElement(vector<int> &arr) {
//     int n = arr.size();
//     int maxi = arr[n-1];
//     vector<int> hashh(maxi, 0);
//     for(int i=0; i<n; i++) {
//         hashh[arr[i]]++;
//     }
//     for(int i=0; i<=maxi; i++) {
//         if(hashh[i] == 1) return i;
//     }
//     return -1;
// }

// int getSingleElement(vector<int> &arr) {
//     int n = arr.size();
//     unordered_map<int, int> mpp;
//     for(int i=0; i<n; i++) {
//         mpp[arr[i]]++;
//     }
//     for(auto it : mpp) {
//         if(it.second == 1) return it.first;
//     }
//     return -1;
// }

int getSingleElement(vector<int> &arr) {
    int n = arr.size();
    int xor1 = 0;
    for(int i=0; i<n; i++) {
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

int main() {
    vector<int> arr = {1,1,2,3,3,4,4};
    cout << getSingleElement(arr) << endl;
    return 0;
}