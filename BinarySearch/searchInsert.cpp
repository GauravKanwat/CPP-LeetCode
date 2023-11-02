#include<iostream>
using namespace std;

// int binarySearchHelper(int start, int end, vector<int>&arr, int target) {
//     if(start > end) return start;
//     int mid = (start + end) / 2;
//     if(arr[mid] == target) return mid;
//     if(arr[mid] < target) return binarySearchHelper(mid + 1, end, arr, target);
//     else return binarySearchHelper(start, mid - 1, arr, target);
// }

int searchInsert(vector<int>& arr, int target)
{
	// Write your code here.
    int n = arr.size();
    int start = 0, end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

int main()
{
    vector<int> arr = {1,2,4,7};
    int m = 6;
    cout << searchInsert(arr, m) << endl;
    return 0;
}