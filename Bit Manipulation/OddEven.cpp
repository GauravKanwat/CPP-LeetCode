#include<iostream>
using namespace std;

string oddEven(int N){
    // Write your code here.
    if(N & 1) return "odd";
    else return "even";
}

int main()
{
    int n = 5;
    cout << oddEven(n) << endl;
    return 0;
}