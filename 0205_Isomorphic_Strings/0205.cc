
#include <assert.h>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::set;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Solution {
 public:
  bool isIsomorphic(const string s, const string t) {
    if (s.size() != t.size()) return false;
    set<char> mapped_lettters;
    unordered_map<char, char> letters_map;
    for (size_t i = 0; i < s.size(); ++i)
      if (letters_map.count(s[i]) == 0) {
        letters_map.insert({s[i], t[i]});
        if (!mapped_lettters.insert(t[i]).second) return false;
      } else if (letters_map[s[i]] != t[i])
        return false;
    return true;
  }
};

int main(void) {
  Solution sln;
  assert(!sln.isIsomorphic("ab", "aa"));
  assert(sln.isIsomorphic("13", "42"));
  return 0;
}
