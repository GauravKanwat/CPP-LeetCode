#include<iostream>
using namespace std;

int binarySearchHelper(int start, int end, vector<int>&arr, int target) {
    if(start > end) return start;
    int mid = (start + end) / 2;
    if(arr[mid] == target) return binarySearchHelper(mid + 1, end, arr, target);
    if(arr[mid] > target) return binarySearchHelper(start, mid - 1, arr, target);
    else return binarySearchHelper(mid + 1, end, arr, target);
}

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
    return binarySearchHelper(0, n-1, arr, x);
}

int main()
{
    vector<int> arr = {2,4,6,7};
    int n = arr.size();
    int x = 5;
    cout << upperBound(arr, x, n) << endl;
    return 0;
}