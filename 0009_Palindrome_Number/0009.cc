
// C version instead of C++.
#include <assert.h>
#include <string.h>

bool isPalindrome(int x) {
  if (x < 0) return false;
  char num_str[16] = {'\0'}; // store reversed number; x = 123, num_str is "321";
  size_t i = 0;
  do {
    num_str[i] = static_cast<char>(x % 10);
    x /= 10;
    ++i;
  } while (x != 0);
  const size_t str_len = i;
  for (i = 0; i < str_len / 2; ++i) {
    if (num_str[i] != num_str[str_len - i - 1]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  bool rtn = isPalindrome(123);
  assert(!rtn);

  rtn = isPalindrome(121);
  assert(rtn);

  rtn = isPalindrome(1221);
  assert(rtn);

  rtn = isPalindrome(0);
  assert(rtn);

  rtn = isPalindrome(-1);
  assert(!rtn);

  return 0;
}
