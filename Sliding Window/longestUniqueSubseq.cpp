#include<iostream>
using namespace std;

int longestSubstring(string s) {
    int left = 0, right = 0, len = 0;
    int n = s.size();
    vector<int> mpp(256, -1);
    while(right < n) {
        if(mpp[s[right]] != -1) left = max(mpp[s[right]] + 1, left);
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main()
{
    string s = "abcaabcdba";
    cout << longestSubstring(s) << endl;
    return 0;
}