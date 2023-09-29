#include<iostream>
using namespace std;

class Solution{
    public:
    bool checkSum(int index, vector<int>& ds, vector<int> arr, int sum, int k, int n) {
        if(index == n) {
            if(sum == k) return true;
            else return false;
        }
        if(sum > k) return false;
        sum += arr[index];
        if(checkSum(index+1, ds, arr, sum, k, n)) return true;
        sum -= arr[index];
        if(checkSum(index+1, ds, arr, sum, k, n)) return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        int sum = 0;
        vector<int> ds;
        return checkSum(0, ds, arr, sum, k, n);
    }
};

int main()
{
    vector<int> arr = {10,1,2,7,6,1,5};
    int n = arr.size();
    int k = 8;
    Solution S;
    cout << S.checkSubsequenceSum(n, arr, k) << endl;
    return 0;
}