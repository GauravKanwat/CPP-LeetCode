#include <iostream>
using namespace std;

vector<string> printNTimes(int n) {
    if(n == 0) return vector<string> ();
    vector<string> print = printNTimes(n-1);
    print.push_back("Coding Ninjas");
    return print;
}

int main() {
    int n;
    cin >> n;
    vector<string> print = printNTimes(n);
    for(auto i : print) {
        cout << i << " ";
    }
    cout << endl;
}