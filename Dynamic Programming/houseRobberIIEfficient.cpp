#include<iostream>
using namespace std;

long long rec(vector<int> temp, bool check) {
	int n = temp.size();
	int prev1, prev2 = 0, curri = 0, i = 0;
    if(check) {
        i = 2;
        prev1 = temp[1];
    }
	else {
        i = 1;
        n -= 1;
        prev1 = temp[0];
    }
    
    for( ; i<n; i++) {
		int take = temp[i];
		if(i > 1) take += prev2;
		int notTake = 0 + prev1;
        curri = max(take, notTake);
		prev2 = prev1;
		prev1 = curri;
	}
	return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    return max(rec(valueInHouse, true), rec(valueInHouse, false));
}

int main()
{
    vector<int> houses = {59, 53, 41, 26, 17, 13, 11};
    cout << houseRobber(houses) << endl;
    return 0;
}