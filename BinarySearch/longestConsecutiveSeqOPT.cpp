#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
        //check from the first value and increment the counter
        for(auto it : st) {
            if(st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while(st.find(x+1) != st.end()) {
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
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