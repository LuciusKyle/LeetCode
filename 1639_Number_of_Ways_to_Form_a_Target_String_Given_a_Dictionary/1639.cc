
#include <string>
#include <vector>

using std::string;
using std::vector;

constexpr int kModulo = 1000000007;

class Solution {
 public:
  int numWays(const vector<string>& words, const string target) {
    const int candidate_length = words[0].size();
    vector<vector<int>> ch_count(candidate_length, vector<int>(26));
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < candidate_length; ++j) {
        ++ch_count[j][words[i][j] - 'a'];
      }
    }
    vector<vector<long>> answer(candidate_length, vector<long>(target.size(), 0));
    answer[0][0] = ch_count[0][target[0] - 'a'];
    for (int i = 1, prefix_sum = 0; i < candidate_length; ++i)  // no need to "% kModulo"
      answer[i][0] = answer[i - 1][0] + ch_count[i][target[0] - 'a'];
    for (int i = 1; i < target.size(); ++i) {
      for (int j = i; j < candidate_length; ++j) {
        answer[j][i] = ((ch_count[j][target[i] - 'a'] * answer[j - 1][i - 1]) % kModulo + answer[j - 1][i]) % kModulo;
      }
    }
    return answer.back().back();
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.numWays({"abba", "baab"}, "bab");
  sln.numWays({"acca", "bbbb", "caca"}, "aba");
  sln.numWays({"cbabddddbc", "addbaacbbd", "cccbacdccd", "cdcaccacac", "dddbacabbd", "bdbdadbccb", "ddadbacddd", "bbccdddadd", "dcabaccbbd", "ddddcddadc", "bdcaaaabdd", "adacdcdcdd", "cbaaadbdbb", "bccbabcbab", "accbdccadd", "dcccaaddbc", "cccccacabd", "acacdbcbbc", "dbbdbaccca", "bdbddbddda", "daabadbacb", "baccdbaada", "ccbabaabcb", "dcaabccbbb", "bcadddaacc", "acddbbdccb", "adbddbadab", "dbbcdcbcdd", "ddbabbadbb", "bccbcbbbab", "dabbbdbbcb", "dacdabadbb", "addcbbabab", "bcbbccadda", "abbcacadac", "ccdadcaada", "bcacdbccdb"}, "bcbbcccc");
  sln.numWays({"cabbaacaaaccaabbbbaccacbabbbcb", "bbcabcbcccbcacbbbaacacaaabbbac", "cbabcaacbcaaabbcbaabaababbacbc", "aacabbbcaaccaabbaccacabccaacca", "bbabbaabcaabccbbabccaaccbabcab", "bcaccbbaaccaabcbabbacaccbbcbbb", "cbbcbcaaaacacabbbabacbaabbabaa", "cbbbbbbcccbabbacacacacccbbccca", "bcbccbccacccacaababcbcbbacbbbc", "ccacaabaaabbbacacbacbaaacbcaca", "bacaaaabaabccbcbbaacacccabbbcb", "bcbcbcabbccabacbcbcaccacbcaaab", "babbbcccbbbbbaabbbacbbaabaabcc", "baaaacaaacbbaacccababbaacccbcb", "babbaaabaaccaabacbbbacbcbababa", "cbacacbacaaacbaaaabacbbccccaca", "bcbcaccaabacaacaaaccaabbcacaaa", "cccbabccaabbcbccbbabaaacbacaaa", "bbbcabacbbcabcbcaaccbcacacccca", "ccccbbaababacbabcaacabaccbabaa", "caaabccbcaaccabbcbcaacccbcacba", "cccbcaacbabaacbaaabbbbcbbbbcbb", "cababbcacbabcbaababcbcabbaabba", "aaaacacaaccbacacbbbbccaabcccca", "cbcaaaaabacbacaccbcbcbccaabaac", "bcbbccbabaccabcccacbbaacbbcbba", "cccbabbbcbbabccbbabbbbcaaccaab", "acccacccaabbcaccbcaaccbababacc", "bcacabaacccbbcbbacabbbbbcaaaab", "cacccaacbcbccbabccabbcbabbcacc", "aacabbabcaacbaaacaabcabcaccaab", "cccacabacbabccbccaaaaabbcacbcc", "cabaacacacaaabaacaabababccbaaa", "caabaccaacccbaabcacbcbbabccabc", "bcbbccbbaaacbaacbccbcbababcacb", "bbabbcabcbbcababbbbccabaaccbca", "cacbbbccabaaaaccacbcbabaabbcba", "ccbcacbabababbbcbcabbcccaccbca", "acccabcacbcbbcbccaccaacbabcaab", "ccacaabcbbaabaaccbabcbacaaabaa", "cbabbbbcabbbbcbccabaabccaccaca", "acbbbbbccabacabcbbabcaacbbaacc", "baaababbcabcacbbcbabacbcbaaabc", "cabbcabcbbacaaaaacbcbbcacaccac"}, "acbaccacbbaaabbbabac");
  return 0;
}
