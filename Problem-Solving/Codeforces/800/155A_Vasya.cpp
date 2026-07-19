#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    cin >> x;
    
    int low = x;
    int high = x;
    int ans = 0;
    
    for (int i = 1; i < n; i++) {
        cin >> x;
        
        if (x > high) {
            high = x;
            ans++;
        } else if (x < low) {
            low = x;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
