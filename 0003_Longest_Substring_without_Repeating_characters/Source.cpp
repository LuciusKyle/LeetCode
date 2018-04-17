
#include<algorithm>
#include<string>
#include<array>

using std::string;



class Solution {
public:
	int lengthOfLongestSubstring(const string s) {
		int max_len = 0;
		int start = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (dict[s[i]] > start) {
				start = dict[s[i]];
			}
			dict[s[i]] = i;
			max_len = std::max(max_len, i - start);
		}
		return max_len;
	}
private:
	std::array<int, 255> dict{ 0 };
};

int main(void)
{
	Solution sln;
	auto rtn = sln.lengthOfLongestSubstring("bbbbbb");

	return 0;
}