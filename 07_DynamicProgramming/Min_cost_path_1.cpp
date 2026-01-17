#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinValue(vector<vector<int>>& cost, int x, int y) {
    int m = cost.size();
    int n = cost[0].size();

    if (x >= m || y >= n) {
        return INT_MAX;
    }

    if (x == m - 1 && y == n - 1) {
        return cost[x][y];
    }

    int right = findMinValue(cost, x, y + 1);
    int down = findMinValue(cost, x + 1, y);
    int diagonal = findMinValue(cost, x + 1, y + 1);

    int minPath = min({right, down, diagonal});

    if (minPath == INT_MAX) return INT_MAX;

    return cost[x][y] + minPath;
}

int minCost(vector<vector<int>>& cost) {
    return findMinValue(cost, 0, 0);
}

int main() {
    vector<vector<int>> cost = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };

    cout << minCost(cost) << endl;
    return 0;
}
