#include <iostream>
using namespace std;

class Solution
{
public:
    // int missingNumber(vector<int> &nums) {
    //     int a = 0, b= 0;
    //     int n = nums.size();
    //     for(int i=1; i<=n; i++) {
    //         a += nums[i-1];
    //         b += i;
    //     }
    //     return (b-a);
    // }

    //better approach
    int missingNumber(vector<int> &nums) {
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<nums.size(); i++) {
            xor1 = xor1 ^ (i+1);
            xor2 = xor2 ^ nums[i];
        }
        return xor1 ^ xor2;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {3, 0, 1};
    cout << S.missingNumber(nums) << endl;
    return 0;
}