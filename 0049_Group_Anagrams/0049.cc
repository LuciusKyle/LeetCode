
#include <memory.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> temp_answer;
    temp_answer.reserve(strs.size() + 32);
    char charactor_count[26] = {'\0'};
    for (const string& str : strs) {
      memset(charactor_count, 0, 26);
      for (const char ch : str)
        ++charactor_count[ch - 'a'];
      temp_answer[string(charactor_count, 26)].push_back(str);
    }
    vector<vector<string>> rtn;
    for (auto& vec : temp_answer)
      rtn.push_back(std::move(vec.second));
    return rtn;
  }
};

int main(void) {
  Solution sln;
  vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};
  // vector<string> vec{ "ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo" };
  auto rtn = sln.groupAnagrams(vec);

  return 0;
}
