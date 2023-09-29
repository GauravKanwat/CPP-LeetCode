#include<iostream>
using namespace std;

void printF(int index, int n, vector<int>& ds, vector<int> arr) {
    if(index == n) {
        for(auto i : ds) cout << i << " ";
        if(ds.size()==0) {
        cout << "{}";
        }
        cout << endl;
        return;
    }
    printF(index + 1, n, ds, arr);
    ds.push_back(arr[index]);
    printF(index + 1, n, ds, arr);
    ds.pop_back();
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    printF(0, arr.size(), ds, arr);
    return 0;
}