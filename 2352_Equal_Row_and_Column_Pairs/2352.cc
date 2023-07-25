
#include <string.h>

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int equalPairs(const vector<vector<int>>& grid) {
    std::unordered_map<string, int> columns_count;
    const int n = grid.size();
    char* str = new char[n * sizeof(int)];
    for (int column = 0; column < n; ++column) {
      // memset(str, 0, n * sizeof(int));
      for (int row = 0; row < n; ++row)
        memcpy(str + row * sizeof(int), &(grid[row][column]), sizeof(int));
      ++columns_count[string(str, n * sizeof(int))];
    }
    delete[] str;
    int answer = 0;
    for (int row = 0; row < n; ++row)
      answer += columns_count[string(reinterpret_cast<const char*>(grid[row].data()), n * sizeof(int))];
    return answer;
  }
};
