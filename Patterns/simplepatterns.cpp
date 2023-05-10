#include<bits/stdc++.h>
using namespace std;

void basicRectangle(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << " * ";
        }
        cout << endl;
    }
}

void leftPyramid(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void nTriangle(int n) {
	// Write your code here
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			cout << j+1 << " ";
		}
		cout << endl;
	}
}

void seeding(int n) {
	// Write your code here.
	for(int i=n; i>=0; i--) {
		for(int j=0; j<i; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}

void nStarTriangle(int n) {
    for(int i=0; i<n; i++) {
        //Space
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        
        //Stars
        for(int j=0; j<2*i+1; j++) {
            cout << "*";
        }

        //Space
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void nStarInvTriangle(int n) {
    // Write your code here.
    for(int i=0; i<n; i++) {
        //Space
        for(int j=0; j<i; j++) {
            cout << " ";
        }

        //Stars
        for(int j=2*n-i-1; j>i; j--) {
            cout << "*";
        }

        //Space
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void nStarDiamond(int n) {
    // Write your code here.
    for(int i=0; i<2*n; i++) {
        //Space
        for(int j=0; j<n; j++) {
            cout << " ";
        }

        //Stars
        for(int j=0; j<i+1; j++) {
            cout << "*";
        }

        //Space
        for(int j=0; j<n; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    // basicRectangle(n);
    // leftPyramid(n);
    // seeding(n);
    nStarDiamond(n);
}