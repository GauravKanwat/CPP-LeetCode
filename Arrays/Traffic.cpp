#include<iostream>
using namespace std;

int traffic(int n, int m, vector<int> vehicle) {
	// Write your code here.
    for(int i=0; i<n; i++) {
        if(vehicle[i] == 0 && m) {
            vehicle[i] = 1;
            m--;
        }
    }
    int count = 0;
    for(int i=0; i<n; i++) {
        if(vehicle[i] == 1) count++;
    }
    return count;
}


int main()
{
    vector<int> vehicle = {0, 1, 0, 0, 1, 0};
    int m = 3;
    cout << traffic(vehicle.size(), m, vehicle) << endl;
    return 0;
}