#include <iostream>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> result;
    int n = a.size();
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--) {
        if(maxi > a[i]) {
            continue;
        }
        else if(maxi <= a[i]) {
            result.push_back(i);
            maxi = a[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> a = {1,2,2,1};
    for(auto i : superiorElements(a)) cout << i << " ";
    cout << endl;
    return 0;
}