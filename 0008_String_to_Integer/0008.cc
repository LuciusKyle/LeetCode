

// C version instead of C++.

#include <assert.h>
#include <string.h>

int myAtoi(char* str) {
  bool positive_integer = true;
  bool started = false;
  size_t i = 0;
  int rtn = 0;
  while (str[i] != '\0')  // assume the C-style string is null-terminated, as
                          // <stdlib.h> does.
  {
    if (!started)
      if (('0' <= str[i] && str[i] <= '9') || str[i] == '-') {
        started = true;
        if (str[i] == '-') {
          positive_integer = false;
          ++i;
        }
      }
    if (started) {
      if ('0' <= str[i] && str[i] <= '9') {
        rtn *= 10;
        rtn += str[i] - ('0' - 0);
      } else
        break;
    }
    ++i;
  }
  return rtn * (positive_integer ? 1 : -1);
}

int main(void) {
  char str[16] = {'\0'};

  strcpy(str,
         "abc12");  // LeetCode problem sample function requires a "char *"
                    // parameter instead of "const char *" parameter. so I can't
                    // call the function like this: myAtoi("some string");
  int rtn = myAtoi(str);
  assert(rtn == 12);

  strcpy(str, "abc-12");
  rtn = myAtoi(str);
  assert(rtn == -12);

  strcpy(str, "a-bc12");
  rtn = myAtoi(str);
  assert(rtn == 0);
  rtn = atoi("a-bc12"); // see what does the <stdlib.h> version atoi deal with "a-bc12".
  assert(rtn == 0);

  rtn = myAtoi("words and 987");
  assert(rtn == 987);

  return 0;
}
