
#include <algorithm>
#include <random>
#include <vector>
#include <iostream>

using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  Solution(const vector<int>& w) : sum_(0), counter_(1, 0), re_(rd_()) {
    for (const int num : w) {
      sum_ += num;
      counter_.push_back(sum_);
    }
    dist_.param(decltype(dist_)::param_type(0, sum_ - 1));
  }

  int pickIndex() {
    const int ret = dist_(re_);
    auto iter = std::upper_bound(counter_.cbegin(), counter_.cend(), ret);
    return (--iter) - counter_.cbegin();
  }

 private:
  vector<int> counter_;
  int sum_;
  random_device rd_;
  default_random_engine re_;
  uniform_int_distribution<int> dist_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(void) {
  
  Solution sln({2,3});
  for (int i = 0; i < 20; ++i) cout << sln.pickIndex() << endl;

  return 0;
}