#include<iostream>
using namespace std;

bool isPowerOfTwo(int n)
{	
    // Write your code here.
    return ((n > 0) && (n & ((n-1) == 0 ? 1 : 0)));
}

int main()
{
    int n = 5436;
    if(isPowerOfTwo(n)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}