#include <iostream>
using namespace std;

vector<int> printNos(int x) {
    // Write Your Code Here
    if(x == 0) return vector<int> ();
    cout << x << " ";
    vector<int> result = printNos(x-1);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> print = printNos(n);
    for(auto i : print) {
        cout << i << " ";
    }
    cout << endl;
}