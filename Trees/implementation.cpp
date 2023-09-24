#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if(data == -1) {
        return nullptr;
    }

    cout << "Enter left child's value of " << data << endl;
    root->left = insert(root->left);
    cout << "Enter right child's value of " << data << endl;
    root->left = insert(root->left);
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root);
    return 0;
}