
#include <string.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int longestPalindrome(const vector<string>& words) {
    int dict[26 * 26]{0};
    for (const string& word : words) ++dict[(word[0] - 'a') * 26 + word[1] - 'a'];
    bool repreate_letters = false;
    int length = 0;
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        if (i == j) {
          const int c = dict[i * 27];
          if (c % 2) repreate_letters = true;
          length += 4 * (c / 2);
        } else {
          const int pairs = std::min(dict[i * 26 + j], dict[j * 26 + i]);
          length += 4 * pairs;
          dict[i * 26 + j] -= pairs;
          dict[j * 26 + i] -= pairs;
        }
    return length + (repreate_letters ? 2 : 0);
  }
};

int main(int argc, char* argv[]) {
  vector<string> test_vec{"lc", "cl", "gg"};
  Solution sln;
  sln.longestPalindrome(test_vec);
  return 0;
}