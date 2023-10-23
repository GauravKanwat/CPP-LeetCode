#include<iostream>
using namespace std;

void powerSet(string s) {
    int n = s.size();
    for(int num = 0; num < (1 << n); num++) {
        string sub = "";
        for(int i=0; i<=n-1; i++) {
            if(num & (1 << i)) sub+= s[i];
        }
        cout << sub << " ";
    }
}

int main()
{
    string s = "abc";
    powerSet(s);
    return 0;
}