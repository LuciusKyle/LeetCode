
#include <vector>
#include <random>

using std::vector;

class Solution {
 public:
  Solution(const int N, const vector<int>& blacklist) : e(rd()), dist(0, N - blacklist.size() - 1), blacklist_(blacklist) {
    std::sort(blacklist_);
  }

  int pick() {
    const int ret = dist(e);
    auto iter = std::lower_bound(blacklist_.cbegin(), blacklist_.cend(), ret);

    if (iter == blacklist_.cend()) return ret + (iter - blacklist_.cbegin());
    
  }

    private:
  
  std::random_device rd;
  std::default_random_engine e;
  const std::uniform_int_distribution<int> dist;
  vector<int>blacklist_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */