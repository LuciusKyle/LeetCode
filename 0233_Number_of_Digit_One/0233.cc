
#include <iostream>

using std::cout;
using std::endl;

constexpr int kDigitsFilter[] = {1'000'000'000, 100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};
constexpr int kCountOne[] = {900000001, 80000001, 7000001, 600001, 50001, 4001, 301, 21, 2, 1};

static_assert(std::end(kCountOne) - std::begin(kCountOne) == std::end(kDigitsFilter) - std::begin(kDigitsFilter), "kDigitsFilter and kCountOne size miss match!");

class Solution {
 public:
  int countDigitOne(const int n) {
    if (n < 10) return n != 0;
    for (int i = 0; i < std::end(kDigitsFilter) - std::begin(kDigitsFilter); ++i)
      if (n / kDigitsFilter[i]) return n * kCountOne[i + 1] + countDigitOne(n % kDigitsFilter[i]);
    return 0;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.countDigitOne(10);
  int count_of_one = 0;
  for (int i = 1; i <= 23; ++i) {
    int num = i;
    do {
      if (num % 10 == 1) {
        ++count_of_one;
      }
      num /= 10;
    } while (num != 0);
    const int sln_answer = sln.countDigitOne(i);
    cout << "number: " << i << "\tanswer: " << count_of_one << "\tmy answer: " << sln_answer << "\n";
  }

  return 0;
  count_of_one = 0;
  for (int i = 1; i <= kDigitsFilter[0]; ++i) {
    int num = i;
    do {
      if (num % 10 == 1) {
        ++count_of_one;
      }
      num /= 10;
    } while (num != 0);
    for (const int num : kDigitsFilter) {
      if (num == i) cout << num << ": " << count_of_one << "\n";
    }
  }
  cout << endl;

  return 0;
}