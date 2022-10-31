
#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    const int n = nums.size();
    stack<std::pair<int, int>> num_index_stk;
    num_index_stk.push({nums[0], 0});
    for (int i = 1; i < n; ++i)
      if (nums[i] < num_index_stk.top().first) num_index_stk.push({nums[i], i});

    int max_width = 0;
    for (int i = n - 1; 0 <= i; --i)
      while (!num_index_stk.empty() && num_index_stk.top().first <= nums[i]) {
        if (max_width < i - num_index_stk.top().second)
          max_width = i - num_index_stk.top().second;
        num_index_stk.pop();
      }

    return max_width;
  }
};

int main(int argc, char* argv[]) {
  if (argc == 1) return 0;
  vector<int> test_vec;
  for (int i = 1; i < argc; ++i) {
    test_vec.push_back(atoi(argv[i]));
  }
  Solution sln;
  std::cout << sln.maxWidthRamp(test_vec) << std::endl;
  return 0;
}