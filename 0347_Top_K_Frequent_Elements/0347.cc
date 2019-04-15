
#include <map>
#include <unordered_map>
#include <vector>

using std::multimap;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> num_count;
    for (const int num : nums)
      if (0 < num_count.count(num))
        ++num_count.at(num);
      else
        num_count.insert({num, 0});
    multimap<int, int> result;
    for (auto iter = num_count.cbegin(); iter != num_count.cend(); ++iter) {
      result.insert({iter->second, iter->first});
      if (k < result.size()) result.erase(result.begin());
    }
    vector<int> rtn;
    auto iter = result.crbegin();
    for (int i = 0; i < k; ++i) {
      rtn.push_back(iter->second);
      ++iter;
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  return 0;
}