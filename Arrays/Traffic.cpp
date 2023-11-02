#include<iostream>
using namespace std;
int traffic(int n, int m, vector<int> &vehicle) {
	// Write your code here.
    int sum = 0;
    if(m == 0) {
        for(int i=0; i<n; i++) {
            sum += vehicle[i];
        }
        return sum;
    }
    int maxSum = 0;
    for(int i=0; i<n; i++) {
        if(vehicle[i] == 0) {
            vehicle[i] = 1;
            int currSum = traffic(n, m-1, vehicle);
            maxSum = max(maxSum, currSum);
            vehicle[i] = 0;
        }
    }
    return maxSum;
}


int main()
{
    vector<int> vehicle = {0, 1, 0, 0, 1, 0};
    int m = 3;
    cout << traffic(vehicle.size(), m, vehicle) << endl;
    return 0;
}