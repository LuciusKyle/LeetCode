
#include <string.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int compress(vector<char>& chars) {
    char pre_char = chars[0];
    short char_repeation = 1, compressed_index = 0;
    for (int i = 1; i < chars.size(); ++i) {
      if (chars[i] != pre_char) {
        chars[compressed_index++] = pre_char;
        if (char_repeation != 1) {
          const string repeations = std::to_string(char_repeation);
          memcpy(chars.data() + compressed_index, repeations.data(), repeations.size());
          compressed_index += repeations.size();
          char_repeation = 1;
        }
        pre_char = chars[i];
      } else {
        ++char_repeation;
      }
    }
    chars[compressed_index++] = pre_char;
    if (char_repeation != 1) {
      const string repeations = std::to_string(char_repeation);
      memcpy(chars.data() + compressed_index, repeations.data(), repeations.size());
      compressed_index += repeations.size();
    }
    return compressed_index;
  }
};