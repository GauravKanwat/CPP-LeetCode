#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        int start;
        int ansStart = -1, ansEnd = -1;

        for(int i=0; i<n; i++) {
            if(sum == 0) start = i;
            sum += nums[i];
            if(sum > maxSum) {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0 )
                sum = 0;
        }
        return {maxSum, ansStart, ansEnd};
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution S;
    for(auto i : S.maxSubArray(nums)) cout << i << " ";
    cout << endl;
    return 0;
}