
#include <assert.h>
#include <array>
#include <regex>
#include <set>
#include <string>

using std::array;
using std::regex;
using std::string;

// no need to use array and set. two unordered_map is fast and easy. (unordered_map<string, char> and unordered_map<char, string>)
class Solution {
 public:
  bool wordPattern(const string pattern, const string str) {
    array<string, 26> dict{"***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***", "***"};
    std::set<string> words;
    const regex reg("[[:w:]]+\\b");
    auto pos = str.cbegin();
    const auto end = str.cend();
    std::smatch m;
    size_t i = 0;
    for (; std::regex_search(pos, end, m, reg); pos = m.suffix().first) {
      if (pattern.size() == i) return false;
#if 201402L < __cplusplus
      if (auto insertion_result = words.insert(m.str()); insertion_result.second) {
#else
      auto insertion_result = words.insert(m.str());
      if (insertion_result.second) {
#endif
        if (dict[pattern[i] - 'a'] == "***")
          dict[pattern[i] - 'a'] = m.str();
        else
          return false;
      } else {
        if (dict[pattern[i] - 'a'] != m.str()) return false;
      }
      ++i;
    }
    return i == pattern.size();
  }
};

int main(void) {
  Solution sln;
  assert(sln.wordPattern("aabb", "xu xu bao bao"));
  assert(!sln.wordPattern("aabb", "aabb"));
  return 0;
}
