#include<iostream>
using namespace std;

vector<int> reverse(vector<int>&nums, int i, int n) {
    if(i >= n/2) return nums;
    swap(nums[i], nums[n-i-1]);
    reverse(nums, i+1, n);
    return nums;
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    return reverse(nums, 0, n);
}


int main()
{
    vector<int> nums = {5, 7, 8, 1, 6, 3};
    int n = nums.size();
    vector<int> result = reverseArray(n, nums);
    for(int i : result) cout << i << " ";
    cout << endl;
    return 0;
}