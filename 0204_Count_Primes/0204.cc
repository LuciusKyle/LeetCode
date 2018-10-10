
#include <assert.h>
#include <cmath>
#include <vector>
#include <fstream>

using std::vector;

class Solution {
 public:
  int countPrimes(const int n) {
    int rtn = 0;
    vector<int> prime_numbers;
    prime_numbers.reserve(n / 2);
    for (int i = 2; i < n; ++i) {
      if (is_prime_number(i, prime_numbers)) ++rtn;
    }
    return rtn;
  }

 private:
  bool is_prime_number(const int n) const {
    for (int i = 2; i <= sqrt(n); ++i)
      if (n % i == 0) return false;
    return true;
  }
  bool is_prime_number(const int n, vector<int> &prime_numbers) const {
    const int boundary = sqrt(n);
    for (const int prime_number : prime_numbers) {
      if (n % prime_number == 0) return false;
      if (boundary < prime_number) {
        prime_numbers.push_back(n);
        return true;
      }
    }
    prime_numbers.push_back(n);
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
  bool is_prime_number(const int n, vector<int> &prime_numbers) const {
    const int boundary = sqrt(n);
    for (const int prime_number : prime_numbers) {
      if (n % prime_number == 0) return false;
      if (boundary < prime_number) {
        prime_numbers.push_back(n);
        return true;
      }
    }
    prime_numbers.push_back(n);
    return true;
  }
};

int main(void) {
  std::ofstream file("prime_number.file");
  Solution2 sln;
  vector<int> nums;
  for (int i = 2; i < INT_MAX; ++i) {
    // if (sln.is_prime_number(i, nums)) file << i << ",\n";
    sln.is_prime_number(i, nums);
  }
  for (const int num : nums) {
    file << num << ",\n";
  }
  return 0;
}
