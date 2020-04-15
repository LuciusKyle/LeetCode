
#include <array>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<int> partitionLabels(const string S) {
    // std::array<vector<int>, 26> dict;
    vector<int> dict[26]; // 46% beat. here we don't need to track every position. we only need to know first and last position. 
    for (int i = 0; i < S.size(); ++i) dict[S[i] - 'a'].push_back(i);
    vector<int> rtn;
    int start = 0;
    do {
      int end = dict[S[start] - 'a'].back();
      for (int i = start; i < end; ++i)
        if (end < dict[S[i] - 'a'].back()) end = dict[S[i] - 'a'].back();
      rtn.push_back(end - start + 1);
      start = end;
      start++;
    } while (start < S.size());
    return rtn;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.partitionLabels("ababcbacadefegdehijhklij");
  rtn = sln.partitionLabels("z");
  rtn = sln.partitionLabels("qvmwtmzzse");
  return 0;
}
