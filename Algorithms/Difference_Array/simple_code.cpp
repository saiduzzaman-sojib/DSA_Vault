#include <iostream>

using namespace std;

const int N = 100005;
long long diff[N];
long long a[N];

void update(int l, int r, long long val) {
    diff[l] += val;      
    diff[r + 1] -= val;  
}

int main() {
    
    int n = 7;

    update(0, 2, 5); //[5, 0, 0, -5, 0, 0, 0]
    update(1, 3, 6); //[5, 6, 0, -5, -6, 0, 0]
    update(2, 6, 1); //[5, 6, 1, -5, -6, 0, 0]

    a[0] = diff[0];
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + diff[i]; //[5,11,12,7,1,1,1]
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}