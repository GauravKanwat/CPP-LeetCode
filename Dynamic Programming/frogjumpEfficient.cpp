#include<iostream>
using namespace std;

int main()
{
    int n = 8;
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
    int prev2 = heights[0], prev1 = heights[1], curri = 0;
    for(int i=1; i<n; i++) {
        int first = prev1 + fabs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i > 1) second = prev2 + fabs(heights[i] - heights[i-2]);
        curri = min(first, second);
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1 << endl;
    return 0;
}