#include<iostream>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    int start = 0, end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(a[mid] == x) {
            return make_pair(a[mid], a[mid]);
        }
        if(a[mid] < x) start = mid + 1;
        else end = mid - 1;
    }
    return make_pair((end < 0 ? -1 : a[end]), (start > n-1 ? -1 : a[start]));
}

int main()
{
    vector<int> arr = {2,3,4};
    int n = arr.size();
    int x = 1;
    cout << getFloorAndCeil(arr, n, x).first << " " << getFloorAndCeil(arr, n, x).second << endl;
    return 0;
}