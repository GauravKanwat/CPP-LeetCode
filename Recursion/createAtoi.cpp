#include <iostream>
#include <string>
using namespace std;

int recAtoi(string &s, int index, int result) {
    if(index >= s.length()) return result;
    if(s[index] >= '0' and s[index] <= '9') {
        result = result * 10 + s[index] - '0';
    }
    return recAtoi(s, index+1, result);
}

int createAtoi(string s) {
    if(s.length() == 0) return 0;
    int res = recAtoi(s, 0, 0);
    if(s[0] == '-') {
        if(s[1] != '+') res = -1 * res;
    }
    return res;
}

int main() {
    string s = "-+546+er";
    // createAtoi(s);
    int res = createAtoi(s);
    cout << res << endl;
    return 0;
}