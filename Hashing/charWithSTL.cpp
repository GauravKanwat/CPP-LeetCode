#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.length();
    unordered_map<char, int> mpp;
    for(int i=0; i<n; i++) {
        mpp[str[i]]++;
    }
    for(auto i : mpp) {
        cout << i.first << "->" << i.second << endl;
    }
    // int q;
    // cin >> q;
    // while(q--) {
    //     char ch;
    //     cin >> ch;
    //     cout << mpp[ch] << " ";
    // }
}