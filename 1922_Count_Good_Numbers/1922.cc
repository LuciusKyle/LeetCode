
#include <assert.h>

#include <array>
#include <iostream>
#include <map>
#include <unordered_map>

constexpr int kModulo = 1000000007;

template <std::size_t N = 34>
constexpr std::array<int, N> getArray() {
  static_assert(3 <= N && N <= 62);
  std::array<int, N> arr{5, 20};
  for (int i = 2; i < arr.size(); ++i)
    arr[i] = (long long)arr[i - 1] * (long long)arr[i - 1] % kModulo;
  return arr;
}

constexpr auto kAnswerDict = getArray();

class Solution {
 public:
  int countGoodNumbers(long long n) {
    for (int i = kAnswerDict.size() - 1; 0 <= i; --i) {
      long long sub_arr_len = 1ll << i;
      if (sub_arr_len <= n) {
        return (long long)kAnswerDict[i] * (n - sub_arr_len == 0 ? 1 : (long long)countGoodNumbers(n - sub_arr_len)) % kModulo;
      }
    }
    return 1;
  }
};

class Solution_correct {
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

int main(int argc, char* argv[]) {
  Solution sln;
  for (int i = 1; i < 10000; ++i) {
    if (sln.countGoodNumbers(i) != Solution_correct().countGoodNumbers(i)) {
      std::cerr << "wrong answer, input is: " << i << "\noutput is: " << sln.countGoodNumbers(i) << "\nanswer is: " << Solution_correct().countGoodNumbers(i) << std::endl;
      abort();
    }
  }
  assert(711414395 == sln.countGoodNumbers(1000000000000000l));
  return 0;
}
