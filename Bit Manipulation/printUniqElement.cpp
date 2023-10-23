#include<iostream>
using namespace std;

int printUniqElem(int arr[], int n) {
    int XOR;
    for(int i=0; i<n; i++) {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main() {
    int arr[] = {2, 1, 2, 5, 6, 5, 7, 7, 6};
    int n = 9;
    int res = printUniqElem(arr, n);
    cout << res << endl;
    return res;
}