
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

#include <assert.h>
#include <string.h>

int romanToInt(char* s) {
  int dict[256] = {0};  // this is not space efficient, but straight
                        // forward, and easy to understand.
  dict['I'] = 1;
  dict['V'] = 5;
  dict['X'] = 10;
  dict['L'] = 50;
  dict['C'] = 100;
  dict['D'] = 500;
  dict['M'] = 1000;

  int rtn_num = 0;
  size_t len = strlen(s);
  char pre_ch = '\0';
  for (int i = len - 1; i >= 0; --i) {
    if (dict[pre_ch] > dict[s[i]])
      rtn_num -= dict[s[i]];
    else
      rtn_num += dict[s[i]];
    pre_ch = s[i];
  }
  return rtn_num;
}

int main(void) {
  char Roman_num[] = "MCMXCIV";
  int rtn = romanToInt(Roman_num);
  assert(rtn == 1994);

  return 0;
}
