#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int majorityElement(int arr[], int size) {
            int count=0, element;
            for(int i=0; i<size; i++) {
                if(count == 0) {
                    count++;
                    element = arr[i];
                }
                else if(element == arr[i])
                    count++;
                else count--;
            }
            return element;
        }
};
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    Solution solution;
    cout << solution.majorityElement(arr, n);
}