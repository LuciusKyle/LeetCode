
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
  bool isIsomorphic(const string s, const string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> letters_map{
        {'a', '?'}, {'b', '?'}, {'c', '?'}, {'d', '?'}, {'e', '?'}, {'f', '?'},
        {'g', '?'}, {'h', '?'}, {'i', '?'}, {'j', '?'}, {'k', '?'}, {'l', '?'},
        {'m', '?'}, {'n', '?'}, {'o', '?'}, {'p', '?'}, {'q', '?'}, {'r', '?'},
        {'s', '?'}, {'t', '?'}, {'u', '?'}, {'v', '?'}, {'w', '?'}, {'x', '?'},
        {'y', '?'}, {'z', '?'}};
    for (size_t i = 0; i < s.size(); ++i)
      if (letters_map[s[i]] == '?')
        letters_map[s[i]] = t[i];
      else if (letters_map[s[i]] != t[i])
        return false;
    return true;
  }
};

int main(void) {
  Solution sln;
  sln.isIsomorphic("ab", "aa");
  return 0;
}
