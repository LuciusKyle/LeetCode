
#include <assert.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
class Solution {
 public:
  string decodeString(const string s) {
    string content;
    for (int i = 0; i < s.size(); ++i)
      if ('0' <= s[i] && s[i] <= '9') {
        int end = i;
        do {
          ++end;
        } while (s[end] != '[');
        int level = 0;
        do {
          if (s[end] == '[') ++level;
          if (s[end] == ']') --level;
          ++end;
        } while (level != 0);
        content.append(decodeRepeatingString({s.cbegin() + i, s.cbegin() + end}));
        i = end - 1;
      } else if (s[i] != ']') {
        content.push_back(s[i]);
      }
    return content;
  }

 private:
  string decodeRepeatingString(const string& s) {
    const int repeation = atoi(s.c_str());
    string content;
    for (int i = 99 < repeation ? 4 : (9 < repeation ? 3 : 2); i < s.size(); ++i)
      if ('0' <= s[i] && s[i] <= '9') {
        int end = i;
        do {
          ++end;
        } while (s[end] != '[');
        int level = 0;
        do {
          if (s[end] == '[') ++level;
          if (s[end] == ']') --level;
          ++end;
        } while (level != 0);
        content.append(decodeRepeatingString({s.cbegin() + i, s.cbegin() + end}));
        i = end - 1;
      } else if (s[i] != ']') {
        content.push_back(s[i]);
      }
    string result;
    result.reserve(repeation * content.size());
    for (int c = 0; c < repeation; ++c)
      result.append(content);
    return result;
  }
};

int main(int argc, char* argv[]) {
  if (argc == 1) return 0;
  Solution sln;
  cout << sln.decodeString(argv[1]) << endl;
  return 0;

  cout << atoi(argv[1]) << endl;
  return 0;
  assert(sln.decodeString("3[a]2[bc]") == "aaabcbc");
  assert(sln.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
  assert(sln.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") == "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef");
  // s = "3[a2[c]]", return "accaccacc".
}
