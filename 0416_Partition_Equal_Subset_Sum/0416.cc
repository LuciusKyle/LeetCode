
#include <map>
#include <numeric>
#include <unordered_set>
#include <vector>

using std::map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  bool canPartition(const vector<int>& nums) {
    const int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    const int target = sum / 2;
    if (target * 2 != sum) return false;

    unordered_set<int> current_level;
    current_level.insert(0);
    for (const int num : nums) {
      unordered_set<int> next_level;
      next_level.reserve(current_level.size() * 2);
      for (const int sum : current_level) {
        if (sum + num == target) return true;
        next_level.insert(sum);
        next_level.insert(sum + num);
      }
      std::swap(current_level, next_level);
    }
    return false;
  }
};

int main(void) {
  vector<int> test_vec{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  Solution sln;
  bool result = sln.canPartition(test_vec);
  test_vec = {2, 2, 3, 5};
  result = sln.canPartition(test_vec);
  return 0;
}

