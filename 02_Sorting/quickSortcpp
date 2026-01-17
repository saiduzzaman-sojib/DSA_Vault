#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivotIdx = partition(arr, start, end);

        quickSort(arr, start, pivotIdx - 1); // Left side
        quickSort(arr, pivotIdx + 1, end);   // Right side
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
