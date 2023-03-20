
#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

constexpr int kModule = 1000000007;

class Solution {
 public:
  int distinctSubseqII(string s) {
    int pre_char_newly_added[26] = {0};
    int answer = 1;
    for (const char ch : s) {
      const int new_added = (answer - pre_char_newly_added[ch - 'a']) % kModule;
      answer += new_added;
      answer %= kModule;
      pre_char_newly_added[ch - 'a'] += new_added;
      pre_char_newly_added[ch - 'a'] %= kModule;
    }
    return (answer - 1) % kModule;
  }
};

int main(void) {
  int pre_char_index[26] = {-1};
  vector<string> test_strs{"abc", "aba", "aaa", "abab", "abbb", "aaab"};
  const vector<int> answers{7, 6, 3, 11, 7, 7};
  Solution sln;
  for (int i = 0; i < test_strs.size(); ++i) {
    const int result = sln.distinctSubseqII(test_strs[i]);
    cout << "result: " << result << "\tanswer: " << answers[i] << "\t" << (result == answers[i] ? "right" : "wrong") << "\n";
  }
  cout << endl;
  return 0;
}