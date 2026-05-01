#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostPath(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            
            int fromUp = dp[i - 1][j];
            int fromLeft = dp[i][j - 1];
            int fromDiagonal = dp[i - 1][j - 1];

            dp[i][j] = grid[i][j] + min({fromUp, fromLeft, fromDiagonal});
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    vector<vector<int>> cost = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };

    cout << "Minimum Cost Path: " << minCostPath(cost) << endl;

    return 0;
}
