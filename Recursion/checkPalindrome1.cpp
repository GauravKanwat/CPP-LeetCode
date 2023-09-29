#include<iostream>
using namespace std;

bool checkPalindrome(string& str, int i, int n) {
    if(i >= n/2) return true;
    if(str[i] == str[n-i-1]) {
        return checkPalindrome(str, i+1, n);
    }
    else return false;
}

bool isPalindrome(string& str) {
    // Write your code here.
    return checkPalindrome(str, 0, str.length());
}


int main()
{
    string a = "racecar";
    if(isPalindrome(a)) cout << "true";
    else cout << "false";
    return 0;
}