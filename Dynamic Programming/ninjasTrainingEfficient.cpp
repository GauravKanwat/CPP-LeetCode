#include<iostream>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++) {
            temp[last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main()
{
    vector<vector<int>> points = {{1,2,5}, {3,1,1}, {3,3,3}};
    int n = points.size();
    cout << ninjaTraining(n, points) << endl;
    return 0;
}