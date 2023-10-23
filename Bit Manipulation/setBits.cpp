#include<iostream>
#include <math.h>
using namespace std;

int setBits(int N){
    // Write your code here.
    int mask = 1;
    if((N & 1) == 0) return N + 1;
    else {
        while((N & mask) != 0 && mask <= N) {
            mask = mask << 1;
        }
        return (N | mask);
    }
}

int main()
{
    int N = 91;
    cout << setBits(N) << endl;
    return 0;
}