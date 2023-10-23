#include<iostream>
using namespace std;

bool isKthBitSet(int n, int k)
{
    // Write your code here.
    return ((n >> (k-1)) & 1);
}

int main()
{
    int N = 5, k = 1;
    if(isKthBitSet(N, k)) cout << "YES" << endl;
    else cout << "NO" << endl; 
    return 0;
}