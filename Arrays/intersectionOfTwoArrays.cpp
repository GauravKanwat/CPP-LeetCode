#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
	// Write your code here.
    vector<int> result;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(A[i] == B[j]) {
            result.push_back(A[i]);
            i++;
            j++;
        }
        if(A[i] < B[j]) {
            i++;
        }
        if(A[i] > B[j]) {
            j++;
        }
    }
    return result;
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};
    vector<int> result = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}