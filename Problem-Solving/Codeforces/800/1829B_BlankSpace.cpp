#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, s, x;
    cin >> n;
    
    while (n--) {
        cin >> s;
        int max_count = 0;
        int current_count = 0;
        
        for (int i = 0; i < s; i++) {
            cin >> x;
            if (x == 0) {
                current_count++;
                max_count = max(max_count, current_count);
            } else {
                current_count = 0;
            }
        }
        
        cout << max_count << endl;
    }
    
    return 0;
}
