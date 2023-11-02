#include<iostream>
using namespace std;

int binarySearchHelper(int start, int end, vector<int>&arr, int target) {
    if(start > end) return start;
    int mid = (start + end) / 2;
    if(arr[mid] == target) return binarySearchHelper(start, mid - 1, arr, target);
    if(arr[mid] > target) return binarySearchHelper(start, mid - 1, arr, target);
    else return binarySearchHelper(mid + 1, end, arr, target);
}

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	return binarySearchHelper(0, n-1, arr, x);
}

int main()
{
    vector<int> arr = {1,2,2,3};
    int n = arr.size();
    int x = 3;
    cout << lowerBound(arr, n, x) << endl;
    return 0;
}