
#include <stack>
#include <vector>

using std::vector;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    const int rows = matrix.size(), columns = matrix[0].size();
    vector<int> histogram;
    histogram.reserve(columns);
    for (int column = 0; column < columns; ++column)
      histogram.push_back(matrix[0][column] - '0');
    int answer = largestRectangleArea(histogram);
    for (int row = 1; row < matrix.size(); ++row) {
      for (int column = 0; column < columns; ++column)
        histogram[column] = matrix[row][column] == '0' ? 0 : histogram[column] + 1;
      answer = std::max(answer, largestRectangleArea(histogram));
    }
    return answer;
  }

 private:
  int largestRectangleArea(const vector<int>& heights) { // LeetCode 0084.
    std::stack<std::pair<int, int>> inc_stk;  // first: index, second: start_from.
    inc_stk.push({0, 0});
    int answer = heights[0];
    for (int i = 1; i < heights.size(); ++i) {
      int start_from = i;
      while (!inc_stk.empty() && heights[i] <= heights[inc_stk.top().first]) {
        answer = std::max(answer, heights[inc_stk.top().first] * (i - inc_stk.top().second));
        start_from = inc_stk.top().second;
        inc_stk.pop();
      }
      inc_stk.push({i, start_from});
    }
    int farest_pos = heights.size();
    while (!inc_stk.empty()) {
      answer = std::max(answer, heights[inc_stk.top().first] * (farest_pos - inc_stk.top().second));
      inc_stk.pop();
    }
    return answer;
  }
};
