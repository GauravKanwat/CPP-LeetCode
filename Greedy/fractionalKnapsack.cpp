#include <bits/stdc++.h> 
using namespace std;

bool sortIt(pair<int, int> a, pair<int, int> b) {
    if(((double)a.second / a.first) > ((double) b.second / b.first))
        return true;
    return false;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w) {
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double maxValue = 0;
    sort(items.begin(), items.end(), sortIt);
    for(auto i : items) {
        if(w == 0) break;
        if(i.first <= w) {
            w = w - i.first;
            maxValue += i.second;
        }
        else {
            maxValue += (w * (double)i.second / i.first);
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<int> weights = {50,40,90,120,10,200};
    vector<int> value = {40,50,25,100,30,45};
    vector<pair<int, int>> items;
    int n = weights.size();
    int w = 200;

    for(int i=0; i<n; i++) {
        items.push_back(make_pair(weights[i], value[i]));
    }

    cout << maximumValue(items, n, w) << endl;
    // maximumValue(items, n, w);
    return 0;
}