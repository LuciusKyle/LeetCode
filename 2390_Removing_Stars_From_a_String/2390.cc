
#include <string>

using std::string;

class Solution {
 public:
  string removeStars(string s) {
    int curr_index = 0;
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == '*')
        --curr_index;
      else
        s[curr_index++] = s[i];
    // return {s.cbegin(), s.cbegin() + curr_index}; // beats 82%.
    s.resize(curr_index);
    return s; // beats 80%. Why?
  }
};