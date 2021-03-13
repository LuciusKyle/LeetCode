
#include <vector>

using std::vector;

// no error on Linux GCC 10. runtime error on LeetCode.
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<int> rows, columns, next_rows, next_columns;
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[i][j] == 0) {
          rows.push_back(i);
          columns.push_back(j);
        } else
          matrix[i][j] = -1;

    const int elements_count = matrix.size() * matrix[0].size();
    int visited = rows.size();
    while (visited != elements_count) {
      for (int i = 0; i < rows.size(); ++i) {
        if (rows[i] != 0 && matrix[rows[i] - 1][columns[i]] == -1) {
          next_rows.push_back(rows[i] - 1);
          next_columns.push_back(columns[i]);
          matrix[next_rows.back()][next_columns.back()] = matrix[rows[i]][columns[i]] + 1;
          ++visited;
        }
        if (rows[i] != matrix.size() - 1 && matrix[rows[i] + 1][columns[i]] == -1) {
          next_rows.push_back(rows[i] + 1);
          next_columns.push_back(columns[i]);
          matrix[next_rows.back()][next_columns.back()] = matrix[rows[i]][columns[i]] + 1;
          ++visited;
        }
        if (columns[i] != 0 && matrix[rows[i]][columns[i - 1]] == -1) {
          next_rows.push_back(rows[i]);
          next_columns.push_back(columns[i] - 1);
          matrix[next_rows.back()][next_columns.back()] = matrix[rows[i]][columns[i]] + 1;
          ++visited;
        }
        if (columns[i] != matrix[0].size() - 1 && matrix[rows[i]][columns[i] + 1] == -1) {
          next_rows.push_back(rows[i]);
          next_columns.push_back(columns[i] + 1);
          matrix[next_rows.back()][next_columns.back()] = matrix[rows[i]][columns[i]] + 1;
          ++visited;
        }
      }
      rows.swap(next_rows);
      columns.swap(next_columns);
      next_rows.clear();
      next_columns.clear();
    }
    return matrix;
  }
};

int main(void) {
  vector<vector<int>> test_vec{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  Solution sln;
  auto ret = sln.updateMatrix(test_vec);
  return 0;
}
