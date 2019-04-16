
#include <limits.h>
#include <algorithm>
#include <array>
#include <set>
#include <unordered_set>
#include <vector>

using std::set;
using std::unordered_set;
using std::vector;

constexpr std::array base_factors{2, 3, 5};

class Solution_Time_Limit_Exceeded {
 public:
  int nthUglyNumber(int n) {
    vector<int> UglyNumbers;
    UglyNumbers.push_back(1);
    UglyNumbers.push_back(2);
    UglyNumbers.push_back(3);
    UglyNumbers.push_back(4);
    UglyNumbers.push_back(5);
    while (UglyNumbers.size() < n) {
      for (int i = UglyNumbers.back() + 1; true; ++i) {
        if (i % 2 == 0)
          if (std::binary_search(UglyNumbers.cbegin(), UglyNumbers.cend(),
                                 i / 2)) {
            UglyNumbers.push_back(i);
            break;
          }
        if (i % 3 == 0)
          if (std::binary_search(UglyNumbers.cbegin(), UglyNumbers.cend(),
                                 i / 3)) {
            UglyNumbers.push_back(i);
            break;
          }
        if (i % 5 == 0)
          if (std::binary_search(UglyNumbers.cbegin(), UglyNumbers.cend(),
                                 i / 5)) {
            UglyNumbers.push_back(i);
            break;
          }
      }
    }
    return UglyNumbers[n - 1];
  }

 private:
  // not used.
  bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};

class Solution_Wrong_Answer {
 public:
  int nthUglyNumber(int n) {
    set<int> ugly_nums_set;
    ugly_nums_set.insert(1);
    ugly_nums_set.insert(2);
    ugly_nums_set.insert(3);
    ugly_nums_set.insert(5);

    unordered_set<int> pre_nums(ugly_nums_set.cbegin(), ugly_nums_set.cend());
    unordered_set<int> cur_nums;
    while (ugly_nums_set.size() < n) {
      for (auto iter = pre_nums.cbegin(); iter != pre_nums.cend(); ++iter) {
        for (const int base_factor : base_factors) {
          if (*iter < INT_MAX / base_factor)
            cur_nums.insert(*iter * base_factor);
        }
      }
      for (auto iter = cur_nums.cbegin(); iter != cur_nums.cend(); ++iter) {
        ugly_nums_set.insert(*iter);
      }
      std::swap(pre_nums, cur_nums);
      cur_nums.clear();
    }
    while (n < ugly_nums_set.size()) {
      ugly_nums_set.erase(--ugly_nums_set.end());
    }
    return *ugly_nums_set.crbegin();
  }

 private:
  // not used.
  bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> rtn(1, 1);
    vector<size_t> indexes(base_factors.size(), 0);
    while (rtn.size() < n) {
      int min_val = INT_MAX;
      size_t min_index = base_factors.size();
      for (size_t i = 0; i < base_factors.size(); ++i) {
        if (rtn[indexes[i]] * base_factors[i] < min_val) {
          min_val = rtn[indexes[i]] * base_factors[i];
          min_index = i;
        }
      }
      ++indexes[min_index];
      rtn.push_back(min_val);
    }
    return rtn.back();
  }
};

int main(void) {
  Solution sln;
  // sln.nthUglyNumber(10);
  sln.nthUglyNumber(11);
  sln.nthUglyNumber(400);
  sln.nthUglyNumber(421);
  int rtn = sln.nthUglyNumber(1690);
  return 0;
}
