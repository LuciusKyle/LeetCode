

#include <numeric>
#include <vector>

using std::vector;

// Alice is guaranteed to win, return true; beats 100%!
class Solution {
 public:
  bool stoneGame(const vector<int>& piles) {
    dp_.assign(piles.size(), vector<int>(piles.size(), -1));
    const int max_score = stoneGame(piles, 0, piles.size() - 1);
    return std::accumulate(piles.cbegin(), piles.cend(), 0) < (max_score * 2);
  }

 private:
  int stoneGame(const vector<int>& piles, int start, int end) {
    if (start + 1 == end) return std::max(piles[start], piles[end]);
    if (start == end) return 0;
    if (dp_[start][end] != -1) return dp_[start][end];
    if (((end - start) % 2) == 1) {  // Alice's turn
      const int max_score = std::max(piles[start] + stoneGame(piles, start + 1, end), piles[end] + stoneGame(piles, start, end - 1));
      dp_[start][end] = max_score;
      return max_score;
    } else {  // Bob's turn
      // Bos wants to minimize the score.
      const int max_score = std::min(stoneGame(piles, start + 1, end), stoneGame(piles, start, end - 1));
      dp_[start][end] = max_score;
      return max_score;
    }
  }
  vector<vector<int>> dp_;
};