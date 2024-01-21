#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string S){
    // Write your code here.
    int n = S.length();
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(S[i] == '[' or S[i] == '{' or S[i] == '(') {
            st.push(S[i]);
        }
        else {
            if(S[i] == ']' and st.top() == '[') st.pop();
            if(S[i] == '}' and st.top() == '{') st.pop();
            if(S[i] == ')' and st.top() == '(') st.pop();
            else return false;
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main()
{
    string S = "[{}()]";
    if(isBalanced(S)) cout << "true" << endl;
    else cout << "false" << endl;
    // cout << isBalanced(S) << endl;
    return 0;
}