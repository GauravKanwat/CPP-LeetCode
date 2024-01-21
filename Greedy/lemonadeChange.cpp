#include<iostream>
using namespace std;

bool lemonadeChange(vector<int> &bill) {
	// Write your code here.
    int countFive = 0, countTen = 0;
    int n = bill.size();
    for(int i=0; i<n; i++) {
        if(bill[i] == 5) countFive++;
        if(bill[i] == 10) {
            countTen++;
            countFive--;
        }
        if(bill[i] == 20) {
            countFive--;
            countTen--;
        }
    }
    if(countFive >= 0 and countTen >= 0) return true;
    else return false;
}


int main()
{
    vector<int> bill = {5,5,5,10,10,20};
    if(lemonadeChange(bill)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}