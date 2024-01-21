#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            //reverse the array
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int i=n-1; i>=0; i--) {
                if(nums[index] < nums[i]) {
                    swap(nums[index], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution S;
    S.nextPermutation(nums);
    for(auto i : nums) cout << i << " ";
    cout << endl;
    return 0;
}