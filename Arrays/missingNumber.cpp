#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> cmp;
        for(int i=0; i<numsSize+1; i++) {
            cmp.push_back(i);
        }
        int cmpSize = cmp.size();
    }
};

int main()
{
    Solution S;
    vector<int> nums = {3, 0, 1};
    cout << S.missingNumber(nums) << endl;
    return 0;
}