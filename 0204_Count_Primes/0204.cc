
#include <assert.h>
#include <cmath>
#include <fstream>

class Solution {
 public:
  int countPrimes(const int n) {
    int rtn = 0;
    for (int i = 2; i < n; ++i) {
      if (is_prime_number(i)) ++rtn;
    }
    return rtn;
  }

 private:
  bool is_prime_number(const int n) const {
    for (int i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) return false;
    return true;
  }
};

int main01(int argc, char const *argv[]) {
  Solution sln;
  assert(4 == sln.countPrimes(10));
  return 0;
}

class Solution2 {
 private:
  int countPrimes(const int n) {
    int rtn = 0;
    for (int i = 2; i < n; ++i) {
      if (is_prime_number(i)) ++rtn;
    }
    return rtn;
  }

 public:
  bool is_prime_number(const int n) const {
    for (int i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) return false;
    return true;
  }
};

int main(void) {
  std::ofstream file("prime_number.file");
  Solution2 sln;
  for (int i = 2; i < INT_MAX; ++i) {
    if (sln.is_prime_number(i)) file << i << ",\n";
  }
  return 0;
}
