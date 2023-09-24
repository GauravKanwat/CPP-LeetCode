#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    //write your code here
    for(int i=0; i<n; i++) {
        int j = i;
        while(j > 0 and arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
 }

int main() {
    vector<int> arr = {9, 3, 6, 2, 0};
    int n = arr.size();
    insertionSort(arr, n);
    for(auto i : arr) cout << i << " ";
    cout << endl;
}