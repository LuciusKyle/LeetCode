
#include <string>
#include <vector>

using std::string;
using std::vector;

constexpr int kLettersSizeMask = 0xffffffff << 5;

class Solution {
 public:
  int maxLength(const vector<string>& arr) {
  vector<int> str_letters_dict;
    str_letters_dict.reserve(arr.size());
    for (const string& str : arr) {
      int dict = 0;
      bool contain_dupe = false;
      for (const char ch : str) {
        if ((1 << (ch - 'a' + 5)) & dict) contain_dupe = true;
        dict |= 1 << (ch - 'a' + 5);
      }
      dict |= int(str.size());
      if (!contain_dupe)
        str_letters_dict.push_back(dict);
    }
    return maxLength(str_letters_dict, 0, 0);
  }

  int maxLength(const vector<int>& str_letters_dict, const int curr_dict, int curr_index) {
    if (curr_index == str_letters_dict.size()) return curr_dict & ~kLettersSizeMask;
    if (curr_dict & str_letters_dict[curr_index] & kLettersSizeMask) return maxLength(str_letters_dict, curr_dict, curr_index + 1);
    int next_dict = ((curr_dict | str_letters_dict[curr_index]) & kLettersSizeMask) | ((curr_dict & ~kLettersSizeMask) + (str_letters_dict[curr_index] & ~kLettersSizeMask));
    return std::max(maxLength(str_letters_dict, curr_dict, curr_index + 1), maxLength(str_letters_dict, next_dict, curr_index + 1));
  }
};