#include<bits/stdc++.h>
#include<map>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0, right = 0;
    int maxLen = 0;
    long long sum = a[0];
    int n = a.size();
    while(right < n) {
        while(sum > k) {
            sum -= a[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}

int main()
{
    vector<int> a = {0, 2, 5, 3, 3, 4, 4, 3, 0, 5, 5, 4, 4, 4, 3, 2, 0, 2, 3, 1, 3, 0, 4, 3, 1, 4, 5, 2, 4, 3, 1, 4, 5, 0, 3, 4, 0};
    long long k = 52;
    cout << longestSubarrayWithSumK(a, k) << endl;
    return 0;
}