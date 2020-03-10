
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

const unordered_set first_row{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
const unordered_set second_row{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
const unordered_set third_row{'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

class Solution {
 public:
  vector<string> findWords(const vector<string>& words) {
    vector<string> rtn;
    for (const string& word : words)
      if (word.size() < 2) {
        rtn.push_back(word);
        continue;
      } else {
        const unordered_set<char>& this_row = first_row.count(word[0]) != 0 ? first_row : (second_row.count(word[0]) != 0 ? second_row : third_row);
        bool in_this_row = true;
        for (int i = 1; i < word.size(); ++i)
          if (this_row.count(word[i]) != 1) {
            in_this_row = false;
            break;
          }
        if (in_this_row) rtn.push_back(word);
      }
    return rtn;
  }
};

