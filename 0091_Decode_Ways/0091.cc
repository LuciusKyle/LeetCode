
#include <assert.h>

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

const std::unordered_set<string> kDigitsSet{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

class Solution {
 public:
  int numDecodings(const string s) {
    vector<int> answer_cache(s.size(), -1);
    return numDecodings(s, 0, answer_cache);
  }

 private:
  int numDecodings(const string &s, const size_t cur_index, vector<int> &answer_cache) {
    if (cur_index == s.size()) return 0;
    if (cur_index + 1 == s.size()) return kDigitsSet.count({s.cbegin() + cur_index, s.cend()});
    if (cur_index + 2 == s.size()) return kDigitsSet.count({s.cbegin() + cur_index, s.cend()}) + ((s[cur_index] != '0' && s[cur_index + 1] != '0') ? 1 : 0);
    if (answer_cache[cur_index] != -1) return answer_cache[cur_index];
    int rtn = (s[cur_index] == '0' ? 0 : numDecodings(s, cur_index + 1, answer_cache)) + (kDigitsSet.count({s.cbegin() + cur_index, s.cbegin() + cur_index + 2}) == 0 ? 0 : numDecodings(s, cur_index + 2, answer_cache));
    answer_cache[cur_index] = rtn;
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.numDecodings("226");
  assert(sln.numDecodings("226") == 3);
  assert(sln.numDecodings("12") == 2);
  return 0;
}
