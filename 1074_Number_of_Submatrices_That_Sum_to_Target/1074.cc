
#include <assert.h>

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int numSubmatrixSumTarget(const vector<vector<int>>& matrix, const int target) {
    const int rows = matrix.size(), columns = matrix[0].size();
    unordered_map<int, int> sum_count;
    int result = 0;
    sum_count.insert({0, 1});
    vector<int> row_sum(columns);
    for (int r = 0; r < rows; ++r) {
      int prefix_sum_of_row = 0;
      for (int c = 0; c < columns; ++c) {
        prefix_sum_of_row += matrix[r][c];
        row_sum[c] += prefix_sum_of_row;
        const int current_target = row_sum[c] - target;
        if (sum_count.count(current_target) != 0) {
          result += sum_count.at(current_target);
        }
        ++sum_count[row_sum[c]];
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> test_vec = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
  Solution sln;
  int result = sln.numSubmatrixSumTarget(test_vec, 0);
  assert(result == 4);

  return 0;
}
