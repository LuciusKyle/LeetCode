
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    vector<vector<string>> rtn;
    unordered_map<string, size_t> group_map;
    group_map.reserve(strs.size());
    string str_buffer;
    str_buffer.reserve(0x100);
    for (const auto& str : strs) {
      str_buffer = str;
      std::sort(str_buffer.begin(), str_buffer.end());
      if (0 < group_map.count(str_buffer))
        rtn[group_map.at(str_buffer) - 1].push_back(str);
      else {
        rtn.emplace_back(vector<string>{str});
        group_map.insert({str_buffer, rtn.size()});
      }
    }
    return rtn;
  }
};

int main(void)
{
	Solution sln;
	vector<string> vec{ "eat", "tea", "tan", "ate", "nat", "bat" };
	// vector<string> vec{ "ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo" };
	auto rtn = sln.groupAnagrams(vec);

	return 0;
}

