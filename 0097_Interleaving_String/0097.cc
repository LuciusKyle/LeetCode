
#include<string>
#include<vector>

using std::string;
using std::vector;

class Solution {
public:
	bool isInterleave(const string s1, const string s2, const string s3) {
#if 201402L < __cplusplus
		vector dp(s1.size(), vector(s2.size(), 0));
#else
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
#endif
		return ((s1.size() + s2.size() != s3.size()) && isInterleave(s1, s2, s3, 0, 0, 0, dp));
	}
private:
	bool isInterleave(const string &s1, const string &s2, const string &s3, const size_t i1, const size_t i2, const size_t i3, vector<vector<int>> &dp) {
		if (i3 == s3.size()) return true;
		if (dp[i1][i2] != 0) return 0 < dp[i1][i2];
		if (i2 < s2.size() && s3[i3] == s2[i2])
			if (isInterleave(s1, s2, s3, i1, i2 + 1, i3 + 1, dp)) {
				dp[i1][i2] = 1;
				return true;
			}
			else
				dp[i1][i2] = -1;
		if (i1 < s1.size() && s3[i3] == s1[i1])
			if (isInterleave(s1, s2, s3, i1 + 1, i2, i3 + 1, dp)) {
				dp[i1][i2] = 1;
				return true;
			}
			else
				dp[i1][i2] = -1;
		return false;
	}
};

int main(void)
{
	Solution sln;
	bool rtn = sln.isInterleave("aabcc", "dbbca", "aadbbbaccc");
	rtn = sln.isInterleave("aabcc", "dbbca", "aadbbcbcac");
	return 0;
}
