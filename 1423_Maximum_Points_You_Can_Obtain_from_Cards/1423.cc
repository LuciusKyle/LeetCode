
#include <assert.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int right_prefix_sum = 0, left_prefix_sum = 0;
    const int l_r_distance = cardPoints.size() - k;
    for (int i = 0; i < l_r_distance; ++i)
      right_prefix_sum += cardPoints[i];
    int minScore = right_prefix_sum;
    for (int i = l_r_distance; i < cardPoints.size(); ++i) {
      right_prefix_sum += cardPoints[i];
      left_prefix_sum += cardPoints[i - l_r_distance];
      minScore = std::min(minScore, right_prefix_sum - left_prefix_sum);
    }
    return right_prefix_sum - minScore;
  }
};

int main(int argc, char *argv[]) {
  vector test_vec = {1, 2, 3, 4, 5, 6, 1};
  Solution sln;
  int rtn = sln.maxScore(test_vec, 3);
  assert(rtn == 12);
  return 0;
}
