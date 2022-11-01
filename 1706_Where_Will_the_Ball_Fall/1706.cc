
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    const int n = grid[0].size(), height = grid.size();
    vector<int> result(n, -1);
    for (int i = 0; i < n; ++i) {
      int pos = i, level = 0;
      for (; level < height; ++level)
        if (grid[level][pos] == 1) {
          if (pos + 1 == n || grid[level][pos + 1] == -1) break;
          ++pos;
        } else {
          if (pos == 0 || grid[level][pos - 1] == 1) break;
          --pos;
        }

      if (level == height)
        result[i] = pos;
    }
    return result;
  }
};

int main(void) {
  vector<vector<int>> test_grid = {{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};
  Solution sln;
  sln.findBall(test_grid);
  return 0;
}