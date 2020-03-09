
#include <stdlib.h>
#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  string convertToBase7(int num) {
    string rtn;
    bool neg = (num < 0);
    if (neg) num *= -1;
    while (num >= 7) {
      rtn.push_back('0' + num % 7);
      num /= 7;
    }
    rtn.push_back('0' + num);
    if (neg) rtn.push_back('-');
    return {rtn.crbegin(), rtn.crend()};
  }
};

int main(void) {
  Solution sln;
  char buf[32] = {0};
  itoa(8, buf, 7);
  for (int i = 0; i < 10000; ++i) {
    itoa(i, buf, 7); // itoa() doesn't accept negative?
    if (sln.convertToBase7(i) != string(buf))
      std::cout << sln.convertToBase7(i) << ": " << buf << std::endl;
  }

  return 0;
}