
#include<algorithm>
#include<string>
#include<map>
#include<set>

using std::string;
using std::map;



class Solution {
public:
	int lengthOfLongestSubstring(const string s) {
		map<char, int> char_index_map;

		int max_len = 0;
		int start = 0;

		for (int i = 0; i < s.size(); ++i) {
			if (char_index_map.count(s[i] > 0)) {
				max_len = std::max(max_len, i - start);
				char_index_map.at(s[i]) = i;
				start = i;
			}
			else {
				char_index_map.insert({ s[i], i });
				max_len = std::max(max_len, i - start);
			}

		}
		return max_len;
	}
};

int main(void)
{
	Solution sln;
	auto rtn = sln.lengthOfLongestSubstring("pwwkew");

	return 0;
}