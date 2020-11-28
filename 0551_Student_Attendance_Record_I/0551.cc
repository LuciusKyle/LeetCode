
#include <string>

using std::string;

class Solution {
 public:
  bool checkRecord(string s) {
    int Ls = 0, As = 0;
    for (const char ch : s) {
      if (ch == 'A') {
        ++As;
        if (2 == As) return false;
      }
      if (ch == 'L') {
        ++Ls;
        if (3 == Ls) return false;
      } else
        Ls = 0;
    }
    return true;
  }
};

int main(const int argc, const char* argv[]) {
  return 0;
}
