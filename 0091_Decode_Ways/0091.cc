
#include <assert.h>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

const std::unordered_set<string> digits_set{
    "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",
    "10", "11", "12", "13", "14", "15", "16", "17", "18",
    "19", "20", "21", "22", "23", "24", "25", "26",
};

class Solution {
 public:
  int numDecodings(const string s) {
#if 201402L < __cplusplus
		vector dp(s.size(), 0);
#else
		vector<int> dp(s.size(), 0);
#endif
    return numDecodings(s,0,dp);
    
    return 0;
  }

 private:
  int numDecodings(const string &s, const size_t cur_index, vector<int> &dp){
    if(cur_index==s.size()) return 0;
    if(cur_index==s.size() - 1) return 1;
    if(cur_index == s.size()  -2) return digits_set.count({s.cbegin() + cur_index, s.cend() + cur_index + 2}) == 0 ? 1 : 2;
    if(dp[cur_index]!=0) return dp[cur_index];
    int rtn = numDecodings(s, cur_index + 1, dp) + (digits_set.count({s.cbegin() + cur_index, s.cend() + cur_index + 2}) == 0 ? 0 : numDecodings(s, cur_index + 2, dp));
    dp[cur_index] = rtn;
    return rtn;
  }
};

int main(void){
  Solution sln;
  int rtn = sln.numDecodings("226");
  assert(sln.numDecodings("226") == 3);
  assert(sln.numDecodings("12") == 2);
  return 0;
}

