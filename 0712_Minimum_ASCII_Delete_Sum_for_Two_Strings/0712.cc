
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minimumDeleteSum(const string s1, const string s2) {
    const int len1 = s1.size(), len2 = s2.size();
    vector<int> curr_line(len2 + 1), next_line(len2 + 1);
    for (int i = len2 - 1; 0 <= i; --i)
      curr_line[i] = curr_line[i + 1] + int(s2[i]);
    for (int i1 = len1 - 1; 0 <= i1; --i1) {
      next_line.back() = curr_line.back() + int(s1[i1]);
      for (int i2 = len2 - 1; 0 <= i2; --i2)
        next_line[i2] = std::min(std::min(int(s1[i1]) + curr_line[i2], int(s2[i2]) + next_line[i2 + 1]), (s1[i1] == s2[i2] ? 0 : int(s1[i1]) + int(s2[i2])) + curr_line[i2 + 1]);
      next_line.swap(curr_line);
    }
    return curr_line.front();
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.minimumDeleteSum("delete", "leet");
  return 0;
}
