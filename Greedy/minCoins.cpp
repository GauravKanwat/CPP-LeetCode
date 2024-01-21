#include<iostream>
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> ans;
    vector<int> currency = {1,2,5,10,20,50,100,500,1000};
    int size = currency.size();
    for(int i=size-1; i>=0; i--) {
        while(n >= currency[i]) {
            n -= currency[i];
            ans.push_back(currency[i]);
        }
    }
    return ans;
}

int main()
{
    int n = 70;
    vector<int> result = MinimumCoins(n);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}