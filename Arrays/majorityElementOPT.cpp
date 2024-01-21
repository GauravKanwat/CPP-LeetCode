#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, element;
        
        for(int i=0; i<n; i++) {
            if(count == 0) {
                count = 1;
                element = nums[i];
            }
            else if(nums[i] == element) {
                count++;
            }
            else count--;
        }
        return element;
    }
};

int main() {
    vector<int> nums = {3,2,3,2};
    Solution S;
    cout << S.majorityElement(nums) << endl;
    return 0;
}