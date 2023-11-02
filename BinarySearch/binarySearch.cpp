#include<iostream>
using namespace std;

int binarySearch(vector<int> &arr, int k) {
    int n = arr.size();
    int start = 0, end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] < k) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {3,4,6,7,9,12,16,17};
    int k = 9;
    cout << binarySearch(arr, k) << endl;
    return 0;
}