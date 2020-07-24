
#include <tbb/tbb.h>

#include <vector>

using std::vector;

// LeetCode version. O(n) extra space and O(n) runtime.
// there is a O(1) extra space and O(n) runtime solution.
class Solution {
 public:
  vector<int> findDisappearedNumbers(const vector<int>& nums) {
    vector<int> temp(nums.size());
    for (const int num : nums) temp[num - 1] = 1;
    vector<int> rtn;
    for (size_t i = 0; i < temp.size(); ++i)
      if (temp[i] == 0) rtn.push_back(i + 1);
    return rtn;
  }
};

// tbb parallel version.
class Solution1 {
 public:
  vector<int> findDisappearedNumbers(const vector<int>& nums) {
    if (nums.size() < 0x200) {
      vector<int> temp(nums.size());
      for (const int num : nums) temp[num - 1] = 1;
      vector<int> rtn;
      for (size_t i = 0; i < temp.size(); ++i)
        if (temp[i] == 0) rtn.push_back(i + 1);
      return rtn;
    }
    vector<int> temp(nums.size());
    tbb::parallel_for(tbb::blocked_range<size_t>(0, nums.size()),
                      [&temp, &nums](const tbb::blocked_range<size_t>& r) {
                        for (size_t i = r.begin(); i != r.end(); ++i)
                          temp[nums[i]] = 1;
                      });

    tbb::concurrent_vector<int> rtn;
    tbb::parallel_for(tbb::blocked_range<size_t>(0, temp.size()),
                      [&temp, &rtn](const tbb::blocked_range<size_t>& r) {
                        for (size_t i = r.begin(); i != r.end(); ++i)
                          if (temp[i] == 0) rtn.push_back(i + 1);
                      });
    vector<int> real_rtn;
    for (const num : rtn) real_rtn.push_back(num);
    return real_rtn;
  }
};

int main(void) {
  Solution sln;
  return 0;
}