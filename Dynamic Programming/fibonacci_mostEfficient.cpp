#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev2 = 0, prev1 = 1, curri = 0;
    for(int i=2; i<=n; i++) {
        curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1 << endl;
    return 0;
}