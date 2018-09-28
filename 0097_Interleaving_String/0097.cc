
#include<string>

using std::string;

class Solution {
public:
	bool isInterleave(const string s1, const string s2, const string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		return isInterleave(s1, s2, s3, 0, 0, 0);
	}
private:
	bool isInterleave(const string &s1, const string &s2, const string &s3, const size_t i1, const size_t i2, const size_t i3) {
		if (i3 == s3.size()) return true;
		if (i2 < s2.size() && s3[i3] == s2[i2])
			if (isInterleave(s1, s2, s3, i1, i2 + 1, i3 + 1))
				return true;
		if (i1 < s1.size() && s3[i3] == s1[i1])
			if (isInterleave(s1, s2, s3, i1 + 1, i2, i3 + 1))
				return true;
		return false;
	}
};

int main(void)
{
	Solution sln;
	bool rtn = sln.isInterleave("aabcc", "dbbca", "aadbbbaccc");
	return 0;
}
