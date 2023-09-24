#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& arr, int low, int high) {
    int pivot = low;
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= arr[pivot] && i <= high-1)
            i++;
        while(arr[j] > arr[pivot] && j >= low+1)
            j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pIndex = findPivot(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 6, 0, 5, 7, 9, 1, 3};
    quickSort(arr, 0, arr.size()-1);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}