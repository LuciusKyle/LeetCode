
#include <map>
#include <unordered_map>

constexpr int kModulo = 1000000007;

class Solution {
 public:
  int countGoodNumbers(long long n) {
    if (n == 1) return 5;
    if (n == 2) return 20;
    const long long sub_str_len = n / 2 + (n / 2 % 2 == 1 ? 1 : 0);
    return (long long)countGoodNumbers(sub_str_len) * (long long)countGoodNumbers(n - sub_str_len) % kModulo;
  }
};
