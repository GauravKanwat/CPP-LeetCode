#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int countCurrent = 0, longest = 1, lastSmallest = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] - 1 == lastSmallest) {
                countCurrent++;
                lastSmallest = nums[i];
            }
            else if(nums[i] != lastSmallest) {
                countCurrent = 1;
                lastSmallest = nums[i];
            }
            longest = max(longest, countCurrent);
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    Solution S;
    int sol = S.longestConsecutive(nums);
    cout << sol << endl;
    return 0;
}