#include<iostream>
using namespace std;

int countSetBits(int N) {
    int count = 0;
    for(int i=1; i<=N; i++) {
        int p = i;
        while(p > 0) {
            if(p & 1) count++;
            p = p >> 1;
        }
    }
    return count;
}

int main()
{
    int n = 12;
    cout << countSetBits(n) << endl;
    return 0;
}