
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n == 1) return 1;
    int max_increase_in_one_round = primes.back() * 2, count = primes.size();
    for (int i = 0; i < count; ++i) {
      for (int multiplier = 2;multiplier<= max_increase_in_one_round / primes[i];++multiplier) {
        primes.push_back(multiplier * primes[i]);
      }
    }
    std::sort(primes.begin(), primes.end());
    count = 0;
    for (int i = 0, pre_num = -1; i < primes.size(); ++i) {
      if (primes[i] != pre_num) {
        pre_num = primes[i];
        primes[count] = primes[i];
        ++count;
      }
    }
    return (n - 2) / count * primes[count - 1] + primes[(n - 2) % count];
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  vector<int> test_vec{2, 3};
  sln.nthSuperUglyNumber(7, test_vec);
  return 0;
}
