#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        for(auto it : mpp) {
            if(it.second > n/2) return it.first;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution S;
    cout << S.majorityElement(nums) << endl;
    return 0;
}