#include<iostream>
using namespace std;

int assignCookie(vector<int> &greed, vector<int> &size) {
	// Write your code here.
	sort(greed.begin(), greed.end());
	sort(size.begin(), size.end());
    int i=0,j=0,count=0;
    while(i < greed.size() && j < size.size()) {
        if(greed[i] <= size[j]) {
            count++;
            i++;
            j++;
        }
        else j++;
    }
    return count;
}

int main()
{
    vector<int> greed = {306, 408, 201, 78, 477, 264, 39, 254, 37, 128, 153, 112, 445, 276, 100, 246, 28, 381,
    384, 300, 373, 98, 398, 33, 142, 297, 103, 423, 18, 415, 238, 85, 187, 265};
    vector<int> size = {233, 93, 264, 291, 70, 490, 236, 495, 201, 178, 285, 120, 77, 32, 233, 401, 367, 434, 214, 243, 358, 
    313, 419, 433, 215, 46, 326};
    cout << assignCookie(greed, size) << endl;
    return 0;
}