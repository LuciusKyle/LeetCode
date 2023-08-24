
#include <algorithm>
#include <string>

using std::string;

class Solution {
 public:
  string reorganizeString(string s) {
    if (s.size() == 1) return s;
    std::pair<int, char> lettrers_count[26];
    for (char ch = 'a'; ch <= 'z'; ++ch) lettrers_count[ch - 'a'] = {0, ch};
    for (const char ch : s) ++lettrers_count[ch - 'a'].first;
    std::sort(std::begin(lettrers_count), std::end(lettrers_count));
    if (lettrers_count[25].first == 1) return s;
    if ((s.size() + 1) / 2 < lettrers_count[25].first) return "";
    int letters_index = 25;
    // even indexes;
    for (int i = 0; i < s.size(); i += 2) {
      s[i] = lettrers_count[letters_index].second;
      --lettrers_count[letters_index].first;
      if (lettrers_count[letters_index].first == 0) --letters_index;
    }
    // odd indexes;
    for (int i = 1; i < s.size(); i += 2) {
      s[i] = lettrers_count[letters_index].second;
      --lettrers_count[letters_index].first;
      if (lettrers_count[letters_index].first == 0) --letters_index;
    }
    return s;
  }
};

int main(void) {
  Solution sln;
  sln.reorganizeString("aaab");
  return 0;
}
