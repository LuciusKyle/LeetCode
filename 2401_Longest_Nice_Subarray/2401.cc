
#include <vector>

using std::vector;

class Solution {
 public:
  int longestNiceSubarray(const vector<int>& nums) {
    // try enlarge window
    int curr_bits = 0, i = 0;
    while (i < nums.size() && (nums[i] & curr_bits) == 0) {
      curr_bits or_eq nums[i];
      ++i;
    }
    int result = i, slow_index = 0;
    while (i < nums.size()) {
      // shrink window
      while ((curr_bits & nums[i]) != 0) {
        curr_bits and_eq ~nums[slow_index];
        ++slow_index;
      }

      // try enlarge window
      while (i < nums.size() && (nums[i] & curr_bits) == 0) {
        curr_bits or_eq nums[i];
        ++i;
      }
      if (result < i - slow_index) result = i - slow_index;
    }
    return result;
  }
};

int main(int argc, char*argv[]) {
  Solution sln;
  sln.longestNiceSubarray({1,3,8,48,10});
  return 0;
}