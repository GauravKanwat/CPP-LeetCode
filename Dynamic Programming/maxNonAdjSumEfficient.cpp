#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> nums = {2, 1, 4, 9};
    int n = nums.size();
    int prev1 = nums[0], prev2 = 0, curri = 0;

    for(int i=1; i<n; i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev1;
        curri = max(take, notTake);
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1 << endl;
    return 0;
}