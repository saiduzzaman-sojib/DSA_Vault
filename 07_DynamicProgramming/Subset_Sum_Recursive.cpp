#include <iostream>
#include <vector>

using namespace std;

bool SubsetSum(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] > sum) {
        return SubsetSum(arr, n - 1, sum);
    }

    return SubsetSum(arr, n - 1, sum) || 
           SubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (SubsetSum(arr, arr.size(), sum)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
