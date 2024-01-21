#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int pt1 = 0, pt2 = n-1;
    while(pt1 >= 0 and pt1 < n and pt2 >= 0 and pt2 < n) {
        if(nums[pt1] + nums[pt2] == target)
            return {pt1, pt2};
        else if(nums[pt1] + nums[pt2] < target) {
            pt1++;
        }
        else pt2--;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {0, 3, 4, 0};
    int target = 0;
    vector<int> result = twoSum(nums, target);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}