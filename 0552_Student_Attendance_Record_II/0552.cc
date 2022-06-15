
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int kModBase = 1'000'000'007;

class Solution {
 public:
  int checkRecord(int n) {
    // tail 'L' is 0, accumulate 'A' is 0.
    // tail 'L' is 0, accumulate 'A' is 1.
    // tail 'L' is 1, accumulate 'A' is 0.
    // tail 'L' is 1, accumulate 'A' is 1.
    // tail 'L' is 2, accumulate 'A' is 0.
    // tail 'L' is 2, accumulate 'A' is 1.
    vector<size_t> answer_cache(6 * (n + 1));
    answer_cache[0] = 1;
    size_t result = 0;
    for (int i = 1; i <= n; ++i) {
      answer_cache[6 * i + 0] += answer_cache[6 * (i - 1) + 0];  // P
      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 0];  // A
      answer_cache[6 * i + 2] += answer_cache[6 * (i - 1) + 0];  // L

      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 1];  // P
      answer_cache[6 * i + 3] += answer_cache[6 * (i - 1) + 1];  // L

      answer_cache[6 * i + 0] += answer_cache[6 * (i - 1) + 2];  // P
      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 2];  // A
      answer_cache[6 * i + 4] += answer_cache[6 * (i - 1) + 2];  // L

      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 3];  // P
      answer_cache[6 * i + 5] += answer_cache[6 * (i - 1) + 3];  // L

      answer_cache[6 * i + 0] += answer_cache[6 * (i - 1) + 4];  // P
      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 4];  // A

      answer_cache[6 * i + 1] += answer_cache[6 * (i - 1) + 5];  // P

      for (int j = 0; j < 6; ++j)
        answer_cache[6 * i + j] %= kModBase;
    }
    return std::accumulate(answer_cache.cbegin() + 6 * n, answer_cache.cend(), size_t(0)) % kModBase;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  const int input = argc == 1 ? 2 : atoi(argv[1]);
  const int output = sln.checkRecord(input);
  cout << output << endl;
  return 0;
}