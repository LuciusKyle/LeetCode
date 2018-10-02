
#include <vector>

using std::vector;

class Solution {
 public:
  bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
    if (matrix.empty()) return false;
    const size_t row_count = matrix.size();
    const size_t column_count = matrix[0].size();
    if (column_count == 0) return false;
    size_t lower_index = 0;
    size_t upper_index = static_cast<int>(row_count * column_count);
    while (1 < upper_index - lower_index) {
      const size_t mid_index = (upper_index + lower_index) / 2;
      if (matrix[mid_index / column_count][mid_index % column_count] < target)
        lower_index = mid_index;
      else if (target < matrix[mid_index / column_count][mid_index % column_count])
        upper_index = mid_index;
      else
        return true;
    }
    return matrix[lower_index / column_count][lower_index % column_count] == target
    || matrix[lower_index / column_count][lower_index % column_count] == target;
  }
};

int main(void) {
  Solution sln;
  vector test_sample{vector{1, 3, 5, 7}, vector{10, 11, 16, 20},
                     vector{23, 30, 34, 50}};
  bool rtn = sln.searchMatrix(test_sample, 3);
  rtn = sln.searchMatrix(test_sample, 17);
  test_sample.clear();
  test_sample.push_back(vector<int>());
  rtn = sln.searchMatrix(test_sample, 1);
  test_sample = vector{vector{1},vector{3}};
  rtn = sln.searchMatrix(test_sample, 4);
  return 0;
}

