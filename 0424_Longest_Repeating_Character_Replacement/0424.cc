
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
    int data[26][4] = {0};  // [][0]: left index, [][1]: right index, [][2]: current max, [][3]: current replacement.
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        ++data[j][1];
        if (s[i] - 'A' != j) ++data[j][3];
        if (k < data[j][3]) {
          do {
            ++data[j][0];
          } while (s[data[j][0] - 1] - 'A' == j && data[j][0] < data[j][1]);
          --data[j][3];
        }
        if (data[j][2] < data[j][1] - data[j][0]) data[j][2] = data[j][1] - data[j][0];
      }
    }
    int max_length = -1;
    for (int i = 0; i < 26; ++i) {
      if (max_length < data[i][2]) max_length = data[i][2];
    }
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