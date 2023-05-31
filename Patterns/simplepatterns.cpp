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

void nStarTriangle2(int n) {
    // Write your code here.
    for(int i=0; i<n; i++) {
        //Left Pyramid
        for(int j=0; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for(int i=0; i<n; i++) {
        for(int j=n-i-1; j>0; j--) {
            cout << "*";
        }
        cout << endl;
    }
}

void nBinaryTriangle(int n) {
    // Write your code here.
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(i % 2 == 0) {
                if(j % 2 == 0) {
                    cout << "1";
                }
                else cout << "0";
            }
            else {
                if(j % 2 == 0) {
                    cout << "0";
                }
                else cout << "1";
            }
        }
        cout << endl;
    }
}

void numberCrown(int n) {
    int space = 2*(n-1);
    // Write your code here.
    for(int i=1; i<=n; i++) {   
        //Numbers
        for(int j=1; j<=i; j++) {
            cout << j;
        }
        //Space
        for(int j=0; j<space; j++) {
            cout << " ";
        }

        //Numbers
        for(int j=i; j>=1; j--) {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

void nNumberTriangle(int n) {
    int count = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void nLetterTriangle(int n) {
    for(int i=0; i<n; i++) {
        char c = 65;
        for(int j=0; j<=i; j++) {
            cout << c;
            c++;
        }
        cout << endl;
    }
}

void nRevLetterTriangle(int n) {
    for(int i=0; i<n; i++) {
        char c = 65;
        for(int j=0; j<n-i; j++) {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}

void alphaRamp(int n) {
    char c = 65;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << c << " ";
        }
        cout << endl;
        c++;
    }
}

void alphaHill(int n) {
    for(int i=1; i<=n; i++) {
        //Space
        for(int j=0; j<n-i; j++) {
            cout << " ";
        }
        //Characters
        for(int j=1; j<=i; j++) {
            cout << j;
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
    // nTriangle(n);
    // nStarTriangle(n);
    // nStarInvTriangle(n);
    // nStarTriangle2(n);
    // nBinaryTriangle(n);
    // numberCrown(n);
    // nNumberTriangle(n);
    // nLetterTriangle(n);
    // nRevLetterTriangle(n);
    // alphaRamp(n);
    alphaHill(n);
}