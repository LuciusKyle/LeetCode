
#include <algorithm>
#include <map>
#include <string>

using std::map;
using std::string;

class Solution {
 public:
  string getHint(const string secret, const string guess) {
    int A = 0, B = 0;
    map<char, size_t> m1;
    map<char, size_t> m2;

    for (size_t i = 0; i < secret.size(); ++i)
      if (secret[i] == guess[i])
        A++;
      else {
        ++m1[secret[i]];
        ++m2[guess[i]];
      }

    for (auto iter = m1.cbegin(); iter != m1.cend(); ++iter)
      B += std::min(iter->second, m2[iter->first]);

    return std::to_string(A) + 'A' + std::to_string(B) + 'B';
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.getHint("1807", "7810");
  rtn = sln.getHint("1123", "0111");
  rtn = sln.getHint("11", "11");
  return 0;
}