#include<iostream>
using namespace std;

void heapify(int n, vector<int> &arr, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(n, arr, largest);
    }
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
    for(int i=n/2-1; i>=0; i--) {
        heapify(n, arr, i);
    }
    return arr;
}

int main()
{
    vector<int> arr = {1,2,3,6,7,8};
    int n = arr.size();
    vector<int> result = MinToMaxHeap(n, arr);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}