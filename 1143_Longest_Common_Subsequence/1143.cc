
#include <assert.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int longestCommonSubsequence(const string text1, const string text2) {
    const int size1 = text1.size(), size2 = text2.size();
    vector<vector<int>> answer_cache(size1 + 1, vector<int>(size2 + 1, 0));
    for (int row = size1 - 1; 0 <= row; --row)
      for (int column = size2 - 1; 0 <= column; --column)
        if (text1[row] == text2[column])
          answer_cache[row][column] = answer_cache[row + 1][column + 1] + 1;
        else
          answer_cache[row][column] = std::max(answer_cache[row][column + 1], answer_cache[row + 1][column]);

    return answer_cache[0][0];
  }
};

int main(void) {
  Solution sln;
  int ret = sln.longestCommonSubsequence("abcde", "ace");
  assert(ret == 3);
  return 0;
}
