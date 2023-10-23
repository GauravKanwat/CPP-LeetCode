#include<iostream>
using namespace std;

void printS(int index, vector<int>& ds, int s, int sum, int arr[], int n, vector<int>& resArr) {
    if(index == n) {
        if(s == sum) {
            for(int i=0; i<n; i++) {
                if(resArr[i] != 1) {
                    if(ds[i] != 0) resArr[i] = 1;
                }
            }
        }
        return;
    }
    ds[index] = arr[index];
    s += arr[index];
    printS(index+1, ds, s, sum, arr, n, resArr);
    s -= arr[index];
    ds[index] = 0;
    printS(index+1, ds, s, sum, arr, n, resArr);    
}

vector<int> sumSeq(int n, int arr[], int sum) {
    vector<int> ds(n, 0);
    vector<int> resArr(n, 0);
    printS(0, ds, 0, sum, arr, n, resArr);
    return resArr;
}

int main()
{
    int arr[] = {49, 73, 58, 30, 72, 44, 78};
    int n = 7;
    int sum = 147;
    vector<int> result = sumSeq(n, arr, sum);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}