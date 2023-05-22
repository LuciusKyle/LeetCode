
#include <forward_list>
#include <map>
#include <unordered_map>
#include <vector>

using std::forward_list;
using std::multimap;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> num_count;
    for (const int num : nums)
      ++num_count[num];
    vector<forward_list<int>> frequence_count(nums.size());  // vector<vector<int>> is also OK!
    for (auto iter = num_count.cbegin(); iter != num_count.cend(); ++iter)
      frequence_count[iter->second - 1].push_front(iter->first);

    vector<int> rtn;
    for (int i = frequence_count.size() - 1; 0 <= i; --i) {
      for (auto iter = frequence_count[i].cbegin(); iter != frequence_count[i].cend(); ++iter)
        rtn.push_back(*iter);
      if (rtn.size() == k) return rtn;
    }

    return rtn;
  }
};

int main(void) {
  Solution sln;
  return 0;
}