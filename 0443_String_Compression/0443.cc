
#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int compress(vector<char>& chars) {
    char pre_char = chars[0], buf[8] = {'\0'};
    short char_repeation = 1, compressed_index = 0;
    for (int i = 1; i < chars.size(); ++i) {
      if (chars[i] != pre_char) {
        chars[compressed_index++] = pre_char;
        if (char_repeation != 1) {
          const int str_len = char_repeation < 10 ? 1 : (char_repeation < 100 ? 2 : (char_repeation < 1000 ? 3 : 4));
          mini_itoa(buf, char_repeation, str_len);
          memcpy(chars.data() + compressed_index, buf, str_len);
          compressed_index += str_len;
        }
        char_repeation = 0;
        pre_char = chars[i];
      }
      ++char_repeation;
    }
    chars[compressed_index++] = pre_char;
    if (char_repeation != 1) {
      const int str_len = char_repeation < 10 ? 1 : (char_repeation < 100 ? 2 : (char_repeation < 1000 ? 3 : 4));
      mini_itoa(buf, char_repeation, str_len);
      memcpy(chars.data() + compressed_index, buf, str_len);
      compressed_index += str_len;
    }
    return compressed_index;
  }

 private:
  void mini_itoa(char* str, int val, const int str_len) {
    for (int i = str_len - 1; 0 <= i; --i) {
      str[i] = '0' + val % 10;
      val /= 10;
    }
  }
};