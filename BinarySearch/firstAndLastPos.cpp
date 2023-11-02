#include<iostream>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    // Write your code here
    int start = 0, end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == k) {
            int first = mid, second = mid;
            while(arr[first] == k and first >= 0) {
                first--;
            }
            while(arr[second] == k and second <= n-1) {
                second++;
            }
            return make_pair(first + 1, second - 1);
        }
        if(arr[mid] < k) start = mid + 1;
        else end = mid - 1;
    }
    return make_pair(-1, -1);
}

int main()
{
    vector<int> arr = {0,0,1,1,2,2,2,2};
    int n = arr.size();
    int k = 2;
    cout << firstAndLastPosition(arr, n, k).first << " " << firstAndLastPosition(arr, n, k).second << endl;
    return 0;
}