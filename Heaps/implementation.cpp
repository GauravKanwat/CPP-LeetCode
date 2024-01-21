#include<iostream>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int x) {
        size = size + 1;
        int index = size;
        arr[index] = x;

        while(index > 1) {
            int parent =   index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void deletefromHeap() {
        if(size == 0) return;

        arr[1] = arr[size];     //Put the last element on the 1st index
        size--;                 //Reduce the size of array by 1

        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && rightIndex < size && arr[i] < arr[leftIndex] && arr[rightIndex] <= arr[leftIndex]) {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(leftIndex < size && rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex]) {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else return;
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int>&arr, int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left < n && arr[largest] < arr[left]) largest = left;
    if(right < n && arr[largest] < arr[right]) largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();

    vector<int> arr = {-1,1,2,3,4,5,6,7};
    int n = arr.size();
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }
    for(int i=1; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}