
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int strStr(const string haystack, const string needle) {
    const auto pos = haystack.find(needle);
    return pos == string::npos ? -1 : int(pos);
  }
};

int main(int argc, char* argv[]) {
  string test_str1 = argc == 3 ? argv[1] : "aabaaabaaac", test_str2 = argc == 3 ? argv[2] : "aabaaac";
  Solution sln;
  int i = test_str1.find(test_str2);
  sln.strStr(test_str1, test_str2);
  return 0;
}
