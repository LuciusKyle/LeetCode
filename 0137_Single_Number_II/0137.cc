

#include <assert.h>
#include <array>
#include <vector>

using std::vector;

constexpr std::array every_bit{
    1 << 0x0,  1 << 0x1,  1 << 0x2,  1 << 0x3,  1 << 0x4,  1 << 0x5,  1 << 0x6,
    1 << 0x7,  1 << 0x8,  1 << 0x9,  1 << 0xa,  1 << 0xb,  1 << 0xc,  1 << 0xd,
    1 << 0xe,  1 << 0xf,  1 << 0x10, 1 << 0x11, 1 << 0x12, 1 << 0x13, 1 << 0x14,
    1 << 0x15, 1 << 0x16, 1 << 0x17, 1 << 0x18, 1 << 0x19, 1 << 0x1a, 1 << 0x1b,
    1 << 0x1c, 1 << 0x1d, 1 << 0x1e, 1 << 0x1f};

constexpr int repeated_times = 3;

// my answer. 16ms running time, 16% beat.
class Solution {
 public:
  int singleNumber(const vector<int>& nums) {
    std::array<int, 32> rtn_bit{0};
    for (const auto num : nums)
      for (size_t i = 0; i < every_bit.size(); ++i)
        if (every_bit[i] & num) ++rtn_bit[i];
    int rtn_val = 0;
    for (size_t i = 0; i < every_bit.size(); ++i)
      if (rtn_bit[i] % repeated_times != 0) rtn_val |= every_bit[i];

    return rtn_val;
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