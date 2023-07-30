
#include <map>
#include <unordered_map>

constexpr int kModulo = 1000000007;

class Solution {
 public:
  int countGoodNumbers(long long n) {
    if (n == 1) return 5;
    if (n == 2) return 20;
    if (answer_cache_.count(n) == 0) {
      const long long sub_str_len = n / 2 + (n / 2 % 2 == 1 ? 1 : 0);
      answer_cache_[n] = (long long)countGoodNumbers(sub_str_len) * (long long)countGoodNumbers(n - sub_str_len) % kModulo;
    }
    return answer_cache_.at(n);
  }

 private:
  std::unordered_map<long long, int> answer_cache_;
};
