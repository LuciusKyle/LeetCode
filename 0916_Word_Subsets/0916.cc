
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    char dict_w2[26] = {0};
    for (const string word : words2) {
      char temp_dict[26] = {0};
      for (const char ch : word) ++temp_dict[ch - 'a'];
      for (int i = 0; i < 26; ++i)
        if (dict_w2[i] < temp_dict[i]) dict_w2[i] = temp_dict[i];
    }
    vector<string> ret;
    for (const string word : words1) {
      char temp_dict[26] = {0};
      for (const char ch : word) ++temp_dict[ch - 'a'];
      bool is_universal = true;
      for (int i = 0; i < 26; ++i)
        if (temp_dict[i] < dict_w2[i]) is_universal = false;
      if (is_universal) ret.push_back(word);
    }
    return ret;
  }
};