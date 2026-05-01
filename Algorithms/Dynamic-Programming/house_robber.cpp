#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& money) {
    int n = money.size();

    if (n == 0) return 0;
    if (n == 1) return money[0];

    int prev2 = 0;
    int prev = money[0];

    for (int i = 1; i < n; i++) {
        int pick = money[i] + prev2;
        int skip = prev;

        int current = max(pick, skip);

        prev2 = prev;
        prev = current;
    }

    return prev;
}

int main() {
    vector<int> houses = {6, 7, 1, 3, 8, 2, 4};
    
    cout << "Maximum Stolen Value: " << rob(houses) << endl;
    
    return 0;
}
