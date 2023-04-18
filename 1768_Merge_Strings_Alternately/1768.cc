
#include <string>

using std::string;

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string rtn;
    rtn.reserve(word1.size() + word2.size());
    int i1 = 0, i2 = 0;
    for (; i1 < word1.size() && i2 < word2.size(); ++i1, ++i2) {
      rtn.push_back(word1[i1]);
      rtn.push_back(word2[i2]);
    }
    rtn.append(word1.begin() + i1, word1.end());
    rtn.append(word2.begin() + i2, word2.end());
    return rtn;
  }
};
