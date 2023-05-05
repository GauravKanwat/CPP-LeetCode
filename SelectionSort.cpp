#include<iostream>
using namespace std;

void swap(int *first, int *second) {
    int temp = *second;
    *second = *first;
    *first = temp;
}

void selectionSort(int *arr, int n) {
    for(int i=0; i<n; i++) {
        int last = n-1-i;
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i) {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted Array: \n";
    printArray(arr, n);
    return 0;
}