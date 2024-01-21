#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positive;
        queue<int> negative;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                positive.push(nums[i]);
            }
            else negative.push(nums[i]);
        }
        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                nums[i] = positive.front();
                positive.pop();
            }
            else {
                nums[i] = negative.front();
                negative.pop();
            }
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {3,1,-2,-5,2,-4};
    Solution S;
    for(auto it : S.rearrangeArray(nums)) cout << it << " ";
    cout << endl;
    return 0;
}