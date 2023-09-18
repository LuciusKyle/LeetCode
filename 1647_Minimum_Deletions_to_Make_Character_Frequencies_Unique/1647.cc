
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  int minDeletions(const string s) {
    int freq[26] = {0};
    for (const char ch : s) ++freq[ch - 'a'];
    std::sort(std::begin(freq), std::end(freq));
    int answer = 0;
    for (int i = 24; 0 <= i; --i)
      if (freq[i + 1] <= freq[i] && freq[i] != 0) {
        answer += (freq[i] - freq[i + 1] + 1);
        freq[i] = freq[i + 1] - 1;
        if (freq[i] == -1) {
          freq[i] = 0;
          --answer;
        }
      }
    return answer;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  const string test_str = argc < 2 ? "aab" : argv[1];
  int ret = sln.minDeletions(test_str);
  std::cout << ret << std::endl;
  return 0;
}