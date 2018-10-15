
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using std::multiset;
using std::string;
using std::vector;

bool func(int a, int b) {
  // log10(a);
  return false;
}

bool a_less_than_b(const string &a, const string &b) {
  const string &shorter_str = a.size() < b.size() ? a : b;
  const string &longer_str = a.size() < b.size() ? b : a;

  for (size_t i = 0; i < longer_str.size(); i += shorter_str.size()) {
    for (size_t ii = 0; ii < shorter_str.size(); ++ii) {
      if (shorter_str[ii] < longer_str[(i + ii) % longer_str.size()])
        return a.size() < b.size();
      if (longer_str[(i + ii) % longer_str.size()] < shorter_str[ii])
        return !(a.size() < b.size());
    }
  }
  return false;
}

class Solution {
 public:
  string largestNumber(const vector<int> &nums) {
    vector<string> nums_str;
    for (const int num : nums) nums_str.push_back(std::to_string(num));

    std::sort(nums_str.begin(), nums_str.end(), [](string &a, string &b) -> bool {
          const string &shorter_str = a.size() < b.size() ? a : b;
          const string &longer_str = a.size() < b.size() ? b : a;
          for (size_t i = 0; i < longer_str.size(); i += shorter_str.size()) {
            for (size_t ii = 0; ii < shorter_str.size(); ++ii) {
              if (shorter_str[ii] < longer_str[(i + ii) % longer_str.size()])
                return a.size() < b.size();
              if (longer_str[(i + ii) % longer_str.size()] < shorter_str[ii])
                return !(a.size() < b.size());
            }
          }
          return false;
        });
    string rtn;
    for (auto r_iter = nums_str.crbegin(); r_iter != nums_str.crend(); ++r_iter)
      if (rtn.empty() || rtn != "0") rtn.append(*r_iter);
    return rtn;
  }
};

int main(void) {
  Solution sln;
  sln.largestNumber({3, 30, 34, 5, 9});

  bool b_rtn = a_less_than_b("1", "2");

  return 0;
}
