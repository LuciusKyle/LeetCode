

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

#include <assert.h>
#include <array>
#include <string>

using std::string;

class Solution {
 public:
  string intToRoman(int num) {
    assert(0 < num && num < 4000);
    char digit[4] = {'\0'};
    digit[0] = num / 1000;
    digit[1] = (num / 100) % 10;
    digit[2] = (num / 10) % 10;
    digit[3] = num % 10;

    string str_rtn;
    str_rtn += OneDigitIntToRaman<'M', '?', '?'>(digit[0]);
    str_rtn += OneDigitIntToRaman<'C', 'D', 'M'>(digit[1]);
    str_rtn += OneDigitIntToRaman<'X', 'L', 'C'>(digit[2]);
    str_rtn += OneDigitIntToRaman<'I', 'V', 'X'>(digit[3]);

    return str_rtn;
  }

 private:
  template <char ONE, char FIVE, char TEN>
  string OneDigitIntToRaman(int num) {
    assert(0 <= num && num < 10);
    char rtn_val[][5] = {{},
                         {ONE},
                         {ONE, ONE},
                         {ONE, ONE, ONE},
                         {ONE, FIVE},
                         {FIVE},
                         {FIVE, ONE},
                         {FIVE, ONE, ONE},
                         {FIVE, ONE, ONE, ONE},
                         {ONE, TEN}};
    return rtn_val[num];
  }
};

int main(void) {
  Solution sln;
  string rtn = sln.intToRoman(10);
  assert(rtn == "X");
  rtn = sln.intToRoman(58);
  assert(rtn == "LVIII");
  rtn = sln.intToRoman(1994);
  assert(rtn == "MCMXCIV");
  return 0;
}
