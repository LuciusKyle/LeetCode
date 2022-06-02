
#include <assert.h>

#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int characterReplacement(const string s, int k) {
    int data[26][3] = {0};  // [][0]: left index, [][1]: current max, [][2]: current replacement.
    for (int i = 0; i < s.size(); ++i)
      for (int j = 0; j < 26; ++j) {
        if (s[i] - 'A' != j) ++data[j][2];
        if (k < data[j][2]) {
          do {
            ++data[j][0];
          } while (s[data[j][0] - 1] - 'A' == j && data[j][0] < i + 1);
          --data[j][2];
        }
        if (data[j][1] < i + 1 - data[j][0]) data[j][1] = i + 1 - data[j][0];
      }

    int max_length = -1;
    for (int i = 0; i < 26; ++i)
      if (max_length < data[i][1]) max_length = data[i][1];

    return max_length;
  }
};

int main(int argc, char* argv[]) {
  std::cout << "__cplusplus: " << __cplusplus << std::endl;
  Solution sln;
  int rtn = sln.characterReplacement("ABAA", 0);
  assert(rtn == 2);
  return 0;
}