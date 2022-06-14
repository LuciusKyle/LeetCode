
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int row = static_cast<int>(triangle.size()) - 2; row >= 0; --row)
      for (int i = 0; i <= row; ++i)
        triangle[row][i] = triangle[row][i] + std::min(triangle[row + 1][i], triangle[row + 1][i + 1]);

    return triangle[0][0];
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> row{2};
  vector<vector<int>> test_sample;
  test_sample.push_back(vector<int>{2});
  test_sample.push_back(vector<int>{3, 4});
  test_sample.push_back(vector<int>{6, 5, 7});
  test_sample.push_back(vector<int>{4, 1, 8, 3});
  int rtn = sln.minimumTotal(test_sample);
  return 0;
}
