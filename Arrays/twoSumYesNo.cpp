#include <iostream>
#include <vector>
using namespace std;

bool twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(target - nums[i] == nums[j]) 
                return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    if(twoSum(nums, target) == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}