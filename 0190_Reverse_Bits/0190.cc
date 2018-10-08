
#include <assert.h>
#include <array>

constexpr std::array<uint32_t, 32> bit_by_bit{
    0x1,        0x2,       0x4,       0x8,       0x10,       0x20,
    0x40,       0x80,      0x100,     0x200,     0x400,      0x800,
    0x1000,     0x2000,    0x4000,    0x8000,    0x10000,    0x20000,
    0x40000,    0x80000,   0x100000,  0x200000,  0x400000,   0x800000,
    0x1000000,  0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000,
    0x40000000, 0x80000000};

class Solution {
 public:
  uint32_t reverseBits(const uint32_t n) {
    uint32_t rtn = 0;
    for (size_t i = 0; i < bit_by_bit.size(); ++i)
      if (bit_by_bit[i] & n) rtn |= bit_by_bit[31 - i];
    return rtn;
  }

 private:
  int hammingWeight(const uint32_t n) {
    int rtn = 0;
    for (const uint32_t b : bit_by_bit)
      if (b & n) ++rtn;
    return rtn;
  }
};

int main(int argc, char const *argv[]) {
  Solution sln;
  assert(964176192 == sln.reverseBits(43261596));
  assert(43261596 == sln.reverseBits(964176192));
  return 0;
}
