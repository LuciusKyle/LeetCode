
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int calculateMinimumHP(const vector<vector<int>>& dungeon) {
    const int rows = dungeon.size();
    const int columns = dungeon[0].size();
    vector<vector<int>> dp(rows, vector<int>(columns, 1));
    dp[rows - 1][columns - 1] = 1 - dungeon[rows - 1][columns - 1] < 1 ? 1 : 1 - dungeon[rows - 1][columns - 1];
    for (int row = rows - 1; 0 <= row; --row) {
      for (int column = columns - 1; 0 <= column; --column) {
        // minimum health required to live in this cell.
        const int now_min = 1 - dungeon[row][column] < 1 ? 1 : 1 - dungeon[row][column];

        // minimum health required to go rightward.
        const int right_min = column + 1 == columns ? 1 : (dp[row][column + 1] - dungeon[row][column + 1] < 1 ? 1 : dp[row][column + 1] - dungeon[row][column + 1]);

        // minimum health required to go downward.
        const int down_min = row + 1 == rows ? 1 : (dp[row + 1][column] - dungeon[row + 1][column] < 1 ? 1 : dp[row + 1][column] - dungeon[row + 1][column]);

        dp[row][column] = std::max(now_min, std::min(right_min, down_min));
      }
    }
    return dp[0][0];
  }
};

int main(void) {
  Solution sln;
  int ret = sln.calculateMinimumHP({{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}});
  assert(ret == 7);
  ret = sln.calculateMinimumHP({{0, -3}});
  assert(ret == 4);
  return 0;
}
