#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* node1 = new Node(arr[0]);
    Node* head = node1;
    Node* tail = node1;
    int n = arr.size();
    for(int i=1; i<n; i++) {
        insertAtTail(tail, arr[i]);
    }
    return head;
}

int main()
{
    vector<int> arr = {4,2,5,1};
    Node *temp = constructLL(arr);
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return 0;
}