#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) 
{
    //write your code here
    int n = arr.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28};
    bubbleSort(arr);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}