#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        this->data = val;
        left = right = NULL;
    }
};

void preOrder(Node* root) {
    Node* node = new Node(root->data);
    if(node == NULL) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(7);
    node->right->right = new Node(8);
    node->left->right->left = new Node(6);
    node->right->right->left = new Node(9);
    node->right->right->right = new Node(10);
    node->left->left->left = NULL;
    node->left->left->right = NULL;
    node->left->right->left->left = NULL;
    node->left->right->left->right = NULL;
    node->right->left->left = NULL;
    node->right->left->right = NULL;
    node->right->right->left->left = NULL;
    node->right->right->left->right = NULL;
    node->right->right->right->left = NULL;
    node->right->right->right->right = NULL;
    preOrder(node);
    return 0;
}