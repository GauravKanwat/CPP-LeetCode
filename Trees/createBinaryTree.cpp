#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node() {
        this->data = 0;
        left = NULL;
    }
    Node(int data) {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* createTree(vector<int>& arr) {
    Node* root = new Node(arr[0]);
    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    createTree(arr);

    return 0;
}