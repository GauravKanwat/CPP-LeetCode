#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++) {
            int more = target - nums[i];
            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[more] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution S;
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    vector<int> result = S.twoSum(nums, target);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}