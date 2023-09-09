#include <iostream>
using namespace std;

vector<int> printNos(int x) {
    // Write Your Code Here
    if(x == 0) return vector<int> ();
    vector<int> numbers = printNos(x-1);
    numbers.push_back(x);
    return numbers;
}

int main() {
    int n;
    cin >> n;
    vector<int> print = printNos(n);
    for(int num : print) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}