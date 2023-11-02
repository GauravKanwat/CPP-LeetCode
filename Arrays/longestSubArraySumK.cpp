#include<bits/stdc++.h>
#include<map>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map <long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<a.size(); i++) {
        sum += a[i];
        if(sum == k) maxLen = max(maxLen, i+1);
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(rem) == preSumMap.end()) 
            preSumMap[sum] = i;
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