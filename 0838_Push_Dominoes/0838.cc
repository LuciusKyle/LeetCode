
#include <limits.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    for (int i = 0, pre_Rs = 0, pre_stable_pos = 0; i < dominoes.size(); ++i) {
      if (dominoes[i] == 'L') {
        if (pre_Rs != 0) {
          for (int j = 1; j < (pre_Rs + 1) / 2; ++j)
            dominoes[i - j] = 'L';
          if (pre_Rs % 2 == 0)
            dominoes[i - pre_Rs / 2] = '.';
          pre_Rs = 0;
        } else {
          for (int j = i; pre_stable_pos <= j; --j)
            dominoes[j] = 'L';
        }
        pre_stable_pos = i + 1;
      } else if (dominoes[i] == 'R') {
        pre_Rs = 1;
      } else if (pre_Rs != 0) {
        ++pre_Rs;
        dominoes[i] = 'R';
      }
    }
    return dominoes;
  }
};