
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> groupThePeople(const vector<int>& groupSizes) {
    vector<int> group_size_count(groupSizes.size() + 1);
    int different_groups = 0;
    for (const int s : groupSizes) {
      ++group_size_count[s];
      if (group_size_count[s] % s == 0) ++different_groups;
    }
    for (int i = 1, curr_count = 0; i < group_size_count.size(); ++i) {
      int t = group_size_count[i] / i;
      group_size_count[i] = curr_count;
      curr_count += t;
    }
    vector<vector<int>> answer(different_groups);
    for (int i = 0; i < groupSizes.size(); ++i) {
      const int curr_size = groupSizes[i];
      auto &vec = answer[group_size_count[curr_size]];
      vec.push_back(i);
      if (vec.size() == curr_size)
        ++group_size_count[curr_size];
    }
    return answer;
  }
};
