
#include <memory.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<int> findAnagrams(const string s, const string p) {
    vector<int> answer;
    const int s_size = s.size(), p_size = p.size();
    if (s_size < p_size) return answer;
    int charactor_count_p[26] = {0}, sliding_charactor_count_s[26] = {0};
    for (const char ch : p) ++charactor_count_p[ch - 'a'];
    for (int i = 0; i < p_size; ++i) ++sliding_charactor_count_s[s[i] - 'a'];
    if (0 == memcmp(charactor_count_p, sliding_charactor_count_s, 26 * sizeof(int)))
      answer.push_back(0);
    for (int i = 0; i < s_size - p_size; ++i) {
      --sliding_charactor_count_s[s[i] - 'a'];
      ++sliding_charactor_count_s[s[i + p_size] - 'a'];
      if (0 == memcmp(charactor_count_p, sliding_charactor_count_s, 26 * sizeof(int)))
        answer.push_back(i + 1);
    }
    return answer;
  }
};