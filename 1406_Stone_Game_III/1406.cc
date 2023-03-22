
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string stoneGameIII(const vector<int>& stoneValue) {
    dp_.assign((stoneValue.size() + 3) * 2, -1);
    const int Alice_score = AliceScore(stoneValue, 0, true);
    const int total_score = std::accumulate(stoneValue.cbegin(), stoneValue.cend(), 0);
    if (Alice_score < total_score - Alice_score)
      return "Bob";
    else if (total_score - Alice_score < Alice_score)
      return "Alice";
    else
      return "Tie";
  }

 private:
  vector<int> dp_;
  int AliceScore(const vector<int>& stoneValue, int index, bool Alice) {
    if (stoneValue.size() <= index) return 0;
    if (index + 1 == stoneValue.size()) return Alice ? stoneValue.back() : 0;
    if (dp_[index * 2 + Alice] != -1) return dp_[index * 2 + Alice];
    if (Alice) {
      if (index + 2 == stoneValue.size()) {
        dp_[index * 2 + Alice] = std::max(stoneValue[index] + AliceScore(stoneValue, index + 1, false), stoneValue[index] + stoneValue[index + 1] + AliceScore(stoneValue, index + 2, false));
        return dp_[index * 2 + Alice];
      }
      dp_[index * 2 + Alice] = std::max(std::max(stoneValue[index] + AliceScore(stoneValue, index + 1, false), stoneValue[index] + stoneValue[index + 1] + AliceScore(stoneValue, index + 2, false)), stoneValue[index] + stoneValue[index + 1] + stoneValue[index + 2] + AliceScore(stoneValue, index + 3, false));
    } else {
      dp_[index * 2 + Alice] = std::min(std::min(AliceScore(stoneValue, index + 1, true), AliceScore(stoneValue, index + 2, true)), AliceScore(stoneValue, index + 3, true));
    }
    return dp_[index * 2 + Alice];
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.stoneGameIII({-1, -2, -3});
  return 0;
}