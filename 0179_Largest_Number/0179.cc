
#include <set>
#include <string>
#include <vector>

using std::multiset;
using std::string;
using std::vector;

class Solution {
 public:
  string largestNumber(const vector<int>& nums) {
    multiset<string> str_set;
    for (const int num : nums) {
      str_set.insert(std::to_string(num));
    }
    string rtn;
    for (auto set_criter = str_set.crbegin(); set_criter != str_set.crend();
         ++set_criter)
      rtn.append(*set_criter);
    return rtn;
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;
  auto rtn = sln.largestNumber({3, 30, 34, 5, 9});
  return 0;
}
