#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
    }
};

//insertion in LL
void insertAtHead(Node* &head, int d) {

    //create a node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    //create a node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void printList(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    printList(head);
    //insert
    // insertAtHead(head, 12);
    insertAtTail(tail, 12);
    printList(head);

    // insertAtHead(head, 15);
    insertAtTail(tail, 15);
    printList(head);
    return 0;
}