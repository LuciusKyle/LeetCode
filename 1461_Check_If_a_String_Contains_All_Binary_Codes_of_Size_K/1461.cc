
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    if (s.size() < k) return false;
    std::unordered_set<string> result_set;
    result_set.reserve(1 << k);
    for (size_t i = 0; i <= s.size() - k; ++i)
      result_set.insert(s.substr(i, k));
    return result_set.size() == 1 << k;
  }
};