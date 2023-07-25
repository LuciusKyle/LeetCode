

#include <assert.h>

#include <array>
#include <vector>

using std::vector;

constexpr int kBitsMask[] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 1 << 31};
constexpr int kRepeatTimes = 3;

class Solution {
 public:
  int singleNumber(const vector<int>& nums) {
    int bits_count[32] = {0};
    for (const auto num : nums)
      for (int i = 0; i < std::end(kBitsMask) - std::begin(kBitsMask); ++i)
        bits_count[i] += ((kBitsMask[i] & num) >> i);
    int result = 0;
    for (int i = 0; i < std::end(kBitsMask) - std::begin(kBitsMask); ++i)
      result |= ((bits_count[i] % kRepeatTimes) == 0 ? 0 : 1) * kBitsMask[i];
    return result;
  }
};

// official solution.
class Solution01 {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
      ones = (ones ^ nums[i]) & ~twos;
      twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
  }
  //- For the first time appear -> save it to "ones";
  //- For the second time appear -> clear "ones" and save it to "twos";
  //- For the third time appear -> try to save to "ones" but value saved in "twos" clear it, so clear "ones"; return ones;
  //- all the bits follow the same rules, so we can handle all the bits in the same time;
};

int main(void) {
  Solution sln;
  assert(3 == sln.singleNumber({2, 2, 2, 3}));
  return 0;
}