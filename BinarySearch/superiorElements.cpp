#include <iostream>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> result;
    int n = a.size();
    int pt1 = 0, pt2 = 1;
    for(int i=0; i<n; i++) {
        int leader = a[i];
        for(int j=i+1; j<n; j++) {
            if(leader < a[j]) {
                leader = -1;
                break;
            }
        }
        if(leader != -1) {
            result.push_back(leader);
        }
    }
    return result;
}

int main() {
    vector<int> a = {5,4,3,2,1,0};
    for(auto i : superiorElements(a)) cout << i << " ";
    cout << endl;
    return 0;
}