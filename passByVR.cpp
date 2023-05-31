#include<iostream>
using namespace std;

void doSomething(string &s) {
    s[0] = 'T';
    cout << s << endl;
}

int main() {
    string s = "Raj";
    doSomething(s);
    cout << s << endl;
    return 0;
}