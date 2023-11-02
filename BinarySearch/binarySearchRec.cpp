#include<iostream>
using namespace std;

int binarySearchHelper(int start, int end, vector<int>&arr, int k) {
    if(start > end) return -1;
    int mid = (start + end) / 2;
    if(arr[mid] == k) return mid;
    else if(arr[mid] < k) return binarySearchHelper(mid + 1, end, arr, k);
    else return binarySearchHelper(start, mid - 1, arr, k);
}

int binarySearch(vector<int> &arr, int k) {
    int n = arr.size();
    return binarySearchHelper(0, n-1, arr, k);
}

int main()
{
    vector<int> arr = {3,4,6,7,9,12,16,17};
    int k = 9;
    cout << binarySearch(arr, k) << endl;
    return 0;
}