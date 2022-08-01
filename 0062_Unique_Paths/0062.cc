
#include <limits.h>
#include <chrono>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  int uniquePaths(const int row, const int column) {
    vector<vector<int>> dp(row, vector<int>(column, INT_MAX));
    return uniquePaths(dp, row - 1, column - 1);
  }

 private:
  int uniquePaths(vector<vector<int>> &dp, const int row, const int column) {
    if (dp[row][column] != INT_MAX) return dp[row][column];
    if (row == 0 || column == 0) return 1;
    return dp[row][column] = uniquePaths(dp, row - 1, column) + uniquePaths(dp, row, column - 1);
  }
};

int main(void) {
  Solution sln;
  auto start = std::chrono::system_clock::now();
  int rtn = sln.uniquePaths(3, 7);
  // do something.
  std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;
  return 0;
}
