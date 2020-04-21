
#include <string>

using std::string;

class Solution {
 public:
  string reorganizeString(const string S) {
    if (S.empty() && S.size() == 1) return S;
    int counter[26]{0};
    for (const char ch : S) ++counter[ch - 'a'];
    string ret;
    size_t s_index = 0;
    for (; s_index < 26; ++s_index)
      if (counter[s_index]) {
        ret.push_back(s_index + 'a');
        --counter[s_index];
        break;
      }

    for (++s_index; s_index < 26 * S.size(); ++s_index) {
      if (counter[s_index % 26]) {
        if (s_index % 26 + 'a' == ret.back()) return "";
        ret.push_back(s_index % 26 + 'a');
        if (ret.size() == S.size()) break;
        --counter[s_index % 26];
      }
    }
    return ret;
  }
};

int main(void) {
  Solution sln;
  sln.reorganizeString("aaab");
  return 0;
}
