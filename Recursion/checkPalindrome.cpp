#include<iostream>
#include<string>
using namespace std;

bool helperFunction(int start, int end, string str) {
    if(start > end) return true;
    if(str[start] == str[end]) return helperFunction(start+1, end-1, str);
    return false;
}

bool checkPalindrome(string& str) {
    return helperFunction(0, str.length()-1, str);
}

int main() {
    string str;
    cin >> str;
    string result;
    cout << checkPalindrome(str);
}