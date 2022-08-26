
#include <set>
#include <unordered_set>
#include <vector>

using std::set;
using std::unordered_set;
using std::vector;

constexpr int kPowerOf2[] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30};

constexpr size_t countDigits(int number) {
  static_assert(8 <= sizeof(size_t));
  size_t ret_val = 0;
  while (number != 0) {
    const int one_digit = number % 10;
    ret_val += size_t(1) << (one_digit * 4);
    number /= 10;
  }
  return ret_val;
}

constexpr size_t kAnswerVec[] = {countDigits(kPowerOf2[0]), countDigits(kPowerOf2[1]), countDigits(kPowerOf2[2]), countDigits(kPowerOf2[3]), countDigits(kPowerOf2[4]), countDigits(kPowerOf2[5]), countDigits(kPowerOf2[6]), countDigits(kPowerOf2[7]), countDigits(kPowerOf2[8]), countDigits(kPowerOf2[9]), countDigits(kPowerOf2[10]), countDigits(kPowerOf2[11]), countDigits(kPowerOf2[12]), countDigits(kPowerOf2[13]), countDigits(kPowerOf2[14]), countDigits(kPowerOf2[15]), countDigits(kPowerOf2[16]), countDigits(kPowerOf2[17]), countDigits(kPowerOf2[18]), countDigits(kPowerOf2[19]), countDigits(kPowerOf2[20]), countDigits(kPowerOf2[21]), countDigits(kPowerOf2[22]), countDigits(kPowerOf2[23]), countDigits(kPowerOf2[24]), countDigits(kPowerOf2[25]), countDigits(kPowerOf2[26]), countDigits(kPowerOf2[27]), countDigits(kPowerOf2[28]), countDigits(kPowerOf2[29]), countDigits(kPowerOf2[30])};
const set kAnswerSet(std::begin(kAnswerVec), std::end(kAnswerVec));

class Solution {
 public:
  bool reorderedPowerOf2(const int n) {
    return kAnswerSet.count(countDigits(n));
  }
};