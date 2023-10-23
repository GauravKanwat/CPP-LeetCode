#include<iostream>
using namespace std;

void printAllSubsequence(int index, int n, vector<int> nums, vector<int> &ds) {
    if(index >= n) {
        for(auto i : ds) cout << i << " ";
        cout << endl;
        return;
    }
    ds.push_back(nums[index]);
    printAllSubsequence(index+1, n, nums, ds);

    ds.pop_back();
    printAllSubsequence(index+1, n, nums, ds);
}

int main()
{
    vector<int> nums = {3, 1, 2};
    vector<int> ds;
    printAllSubsequence(0, nums.size(), nums, ds);
    return 0;
}