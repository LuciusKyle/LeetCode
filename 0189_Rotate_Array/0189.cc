
#include <vector>

using std::vector;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.empty()) return;
    k %= nums.size();
    if (k == 0) return;
    int temp = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      const size_t index_to_go = (i + k) % nums.size();
      temp= nums[index_to_go]  ;
      
    }
  }
};

int main(int argc, char const* argv[]) {
  vector test_sample{1, 2, 3, 4, 5, 6, 7};
  Solution sln;
  sln.rotate(test_sample, 3);

  return 0;
}
