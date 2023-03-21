
#include <string>

using std::string;

class Solution {
 public:
  int maxVowels(string s, int k) {
    int answer = 0;
    for (int i = 0; i < k; ++i)
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ++answer;
    for (int i = k, t_answer = answer; i < s.size(); ++i) {
      if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') --t_answer;
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ++t_answer;
      if (answer < t_answer) answer = t_answer;
    }
    return answer;
  }
};