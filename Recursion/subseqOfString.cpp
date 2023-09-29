#include<iostream>
using namespace std;

void printF(int index, int n, vector<string>& ds, vector<string> str1) {
    if(index == n) {
        for(auto i : ds) cout << i << " ";
        cout << endl;
    }
    ds.push_back(str1[index]);
    printF(index + 1, n, ds, str1);
    ds.pop_back();
    printF(index + 1, n, ds, str1);
}

vector<string> subsequences(string str){
	// Write your code here
	int n = str.length();
    vector<string> ds;
    vector<string> str1(n);
    for(int i=0; i<n; i++) {
        str1[i] = str[i];
    }
    printF(0, n, ds, str1);
    return ds;
}

int main()
{
    string str = "abc";
    vector<string> subseq = subsequences(str);
    for(auto i : subseq) cout << i << " ";
    cout << endl;
    return 0;
}