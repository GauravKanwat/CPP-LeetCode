#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    // get the minimum
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[mini]) mini = j;
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    selectionSort(arr);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}