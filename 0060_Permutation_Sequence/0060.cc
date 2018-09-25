
#include <string>
#include <vector>

using std::string;
using std::vector;

// problem 31: leetcode.com/problems/next-permutation

class Solution {
 public:
  string getPermutation(int n, int k) {
    string rtn;
    for (int i = 1; i <= n; ++i) rtn.push_back(i - 1 + '1');

    for (int i = 1; i < k; ++i) nextPermutation(rtn);

    return rtn;
  }

 private:
  template <typename T>
  void nextPermutation(T& nums) {
    int revers_position = 0;
    for (int i = nums.size() - 1; i > 0 /*don't let i = 0*/; --i) {
      if (nums[i - 1] < nums[i]) {
        revers_position = i;
        for (int ii = nums.size() - 1; ii > i - 1; --ii) {
          if (nums[ii] > nums[i - 1]) {
            nums[ii] ^= nums[i - 1];
            nums[i - 1] ^= nums[ii];
            nums[ii] ^= nums[i - 1];
            break;
          }
        }
        break;
      }
    }
    for (int i = 0; i < (nums.size() - revers_position) / 2; ++i) {
      nums[i + revers_position] ^= nums[nums.size() - 1 - i];
      nums[nums.size() - 1 - i] ^= nums[i + revers_position];
      nums[i + revers_position] ^= nums[nums.size() - 1 - i];
    }
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.getPermutation(3, 3);

  return 0;
}