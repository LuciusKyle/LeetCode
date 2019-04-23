
#include <vector>

using std::vector;

class Solution {
 public:
  bool canPartition(const vector<int>& nums) {
    int target = 0;
    for (const int num : nums) target += num;
    if (target % 2 != 0) return false;
    target /= 2;
    
  }

 private:
  bool canPartition(const vector<int>& nums, size_t cur_index, int target);
  
};

int main(void) {
  Solution sln;
  return 0;
}