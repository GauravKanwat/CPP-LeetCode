#include<iostream>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i=0; i<n; i++) {
        if(num == arr[i]) return i;
    }
    return -1;
}


int main()
{
    vector<int> arr = {6,7,8,4,1};
    int n = arr.size();
    int num = 4;
    int result = linearSearch(n, num, arr);
    cout << result << endl;
    return 0;
}