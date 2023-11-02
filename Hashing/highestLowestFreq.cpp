#include<bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int>& v) {
    int n = v.size();
    map<int, int> hashh;

    for(int i=0; i<n; i++) {
        hashh[v[i]]++;
    }
    vector<int> freq(2);

    int maxFreq = 0, minFreq = n;

    for(auto i : hashh) {
        int element = i.first;
        int count = i.second;

        if(count > maxFreq) {
            freq[0] = element;
            maxFreq = count;
        }
        if(count < minFreq) {
            freq[1] = element;
            minFreq = count;
        }
    }
    return freq;
}

int main() {
    vector<int> v = {1, 2, 3, 1, 1, 4};
    vector<int> result(2);
    result = getFrequencies(v);
    for(int i : result) cout << i << " ";
    cout << endl;
    return 0;
}