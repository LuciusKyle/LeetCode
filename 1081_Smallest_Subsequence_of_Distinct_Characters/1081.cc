#include <array>
#include <string>

using std::string;

class Solution {
 public:
  string smallestSubsequence(string text) {
    std::array<short, 26> ch_dict{0};
    for (const char ch : text) ++ch_dict[ch - 'a'];
    string rtn;
    std::array<bool, 26> ch_visited{false};
    for (const char ch : text) {
      --ch_dict[ch - 'a'];
      while (!rtn.empty() && ch < rtn.back() && !ch_visited[ch - 'a'] &&
             ch_dict[rtn.back() - 'a'] != 0) {
        ch_visited[rtn.back() - 'a'] = false;
        rtn.pop_back();
      }
      if (!ch_visited[ch - 'a']) {
        ch_visited[ch - 'a'] = true;
        rtn.push_back(ch);
      }
    }
    return rtn;
  }
};