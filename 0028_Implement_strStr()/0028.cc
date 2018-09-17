
#include <cstring>

// I didn't use KMP algorithm in this question. brute-force is OK.
int strStr(char* haystack, char* needle) {
  if (needle == nullptr || haystack == nullptr || needle[0] == '\0') return 0;
  const size_t needle_len = strlen(needle);

  size_t i = 0;
  while (haystack[i] != '\0') {
    bool bingo = true;
    for (size_t ii = 0; ii < needle_len; ++ii) {
      if (haystack[i + ii] != needle[ii] || haystack[i + ii] == '\0') {
        bingo = false;
        break;
      }
    }
    if(bingo)
    return i;
    ++i;
  }
  return -1;
}

int main(void){
  char haystack[] = "hello";
  char needle[] = "ll";
  int rtn = strStr(haystack, needle);

  return 0;
}