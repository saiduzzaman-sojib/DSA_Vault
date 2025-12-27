#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int pos, int element, int capacity) {
    if (n >= capacity) {
        cout << "Array is full! Cannot insert." << endl;
        return;
    }
    
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    n++; 
}

int main() {
    int arr[20] = {10, 20, 30, 40, 50}; 
    int n = 5; 
    int capacity = 20; 

    cout << "Before Insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    insertElement(arr, n, 2, 99, capacity); 

    cout << "After Insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}