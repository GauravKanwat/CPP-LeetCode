#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> hash;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        hash[arr[i]]++;
    }

    for(auto i : hash) {
        cout << i.first << "->" << i.second << endl;
    }
    cout << endl;

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
}