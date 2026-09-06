#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << i << " " << n + 2 * i - 1 << " " << n + 2 * i << " ";
    }
    cout << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}