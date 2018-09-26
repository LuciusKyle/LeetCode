
#include <algorithm>
#include <string>

using std::string;

class Solution {
 public:
  string addBinary(const string a, const string b) {
    int index_a = a.size() - 1;  // use signed integer instead of unsigned.
    int index_b = b.size() - 1;  // use signed integer instead of unsigned.
    string reverse_rtn;
    bool carry = false;
    while (index_a >= 0 || index_b >= 0) {
      const int digit = (index_a >= 0 ? (a[index_a] + 1 - '1') : 0) +
                        (index_b >= 0 ? (b[index_b] + 1 - '1') : 0) +
                        (carry ? 1 : 0);
      if (digit / 2 > 0)
        carry = true;
      else
        carry = false;
      reverse_rtn.push_back(static_cast<char>(digit % 2) - (1 - '1'));
      --index_a;
      --index_b;
    }
    if (carry) reverse_rtn.push_back('1');
    return string(reverse_rtn.crbegin(), reverse_rtn.crend());
  }
};

int main(int argc, char const *argv[]) {
  Solution sln;
  auto rtn = sln.addBinary("111", "1111");
  return 0;
}
