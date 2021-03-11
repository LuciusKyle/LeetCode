
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using std::map;
using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  Solution(const int N, vector<int>& blacklist) : e(rd()), dist(0, N - blacklist.size() - 1) {
    std::sort(blacklist.begin(), blacklist.end());
    dict_.insert({-1, 0});
    for (int i = 0, pre_num = -1; i < blacklist.size(); ++i) {
      if (blacklist[i] - 1 == pre_num)
        dict_.rbegin()->second++;
      else
        dict_.insert({blacklist[i] - i, i + 1});

      pre_num = blacklist[i];
    }
    dict_.insert({N, N});
  }

  int pick() {
    const int ret = dist(e);
    auto iter = dict_.upper_bound(ret);
    --iter;
    return ret + iter->second;
  }

 private:
  std::random_device rd;
  std::default_random_engine e;
  std::uniform_int_distribution<int> dist;
  map<int, int> dict_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

int main(int argc, char* argv[]) {
  vector<int> test_blacklist{1};
  Solution sln(3, test_blacklist);
  for (int i = 0; i < 0x2f; ++i) {
    cout << sln.pick() << endl;
  }
  return 0;
}