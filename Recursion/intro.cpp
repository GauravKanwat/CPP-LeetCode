#include<iostream>
int cnt = 0;
using namespace std;

void f() {
    if(cnt == 4) return;
    cout << cnt << endl;
    cnt++;
    f();
}

int main()
{
    f();
    return 0;
}