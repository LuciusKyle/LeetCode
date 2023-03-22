
#include <limits.h>

#include <vector>
#include <map>

using std::vector;

// beats 17%. 
class Solution {
 public:
  int stoneGameII(const vector<int>& piles) {
    Alice_score_.assign(piles.size(), std::map<int,int>());
    Bob_score_.assign(piles.size(), std::map<int,int>());
    return stoneGameII(piles, 0, 1, true);
  }

 private:
  vector<std::map<int,int>> Alice_score_; // don't need std::map if memorise remaining elements count.
  vector<std::map<int,int>> Bob_score_;
  int stoneGameII(const vector<int>& piles, const int index, const int M, const bool Alice) { // bad function design. pass remaining elements count instead of 'M'.
    if (index == piles.size() - 1) return Alice ? piles.back() : 0;
    if (index == piles.size()) return 0;

    if (Alice) {
      if (Alice_score_[index].count(M) != 0) return Alice_score_[index].at(M);
      int score = 0, max_score = 0;
      for (int i = index; i < std::min(int(piles.size()), M * 2 + index); ++i) {
        score += piles[i];
        const int total_score = score + stoneGameII(piles, i + 1, std::max(M, i - index + 1), !Alice);
        if (max_score < total_score) max_score = total_score;
      }
      Alice_score_[index].insert({M, max_score});
      return max_score;
    } else {
      if (Bob_score_[index].count(M) != 0) return Bob_score_[index].at(M);
      int min_score = INT_MAX;
      for (int i = index; i < std::min(int(piles.size()), M * 2 + index); ++i) {
        const int total_score = stoneGameII(piles, i + 1, std::max(M, i - index + 1), !Alice);
        if (total_score < min_score) min_score = total_score;
      }
      Bob_score_[index].insert({M, min_score});
      return min_score;
    }
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.stoneGameII({2, 7, 9, 4, 4});
  return 0;
}