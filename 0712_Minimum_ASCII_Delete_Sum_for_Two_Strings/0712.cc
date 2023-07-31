
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    dp_.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return minimumDeleteSum(s1, s2, 0, 0);
  }

 private:
  vector<vector<int>> dp_;
  int minimumDeleteSum(const string &s1, const string &s2, int i1, int i2) {
    if (dp_[i1][i2] != -1) return dp_[i1][i2];
    if (i1 == s1.size()) {
      const int cost = std::accumulate(s2.cbegin() + i2, s2.cend(), int(0));
      dp_[i1][i2] = cost;
      return cost;
    }
    if (i2 == s2.size()) {
      const int cost = std::accumulate(s1.cbegin() + i1, s1.cend(), int(0));
      dp_[i1][i2] = cost;
      return cost;
    }
    const int delete_i1_cost = int(s1[i1]) + minimumDeleteSum(s1, s2, i1 + 1, i2);
    const int delete_i2_cost = int(s2[i2]) + minimumDeleteSum(s1, s2, i1, i2 + 1);
    const int delete_or_keep_both_cost = (s1[i1] == s2[i2] ? 0 : int(s1[i1]) + int(s2[i2])) + minimumDeleteSum(s1, s2, i1 + 1, i2 + 1);
    dp_[i1][i2] = std::min(delete_or_keep_both_cost, std::min(delete_i1_cost, delete_i2_cost));
    return dp_[i1][i2];
  }
};
