#include<iostream>
using namespace std;
int cutRod(int arr[], int n) {
    if(n <= 0) return 0;
    int q = INT_MIN;
    for(int i=1; i<=n; i++) {
        q = max(q, arr[i-1] + cutRod(arr, n-i));
    }
    return q;
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
            //  1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int n = 30;
    cout << cutRod(arr, n) << endl;
    return 0;
}