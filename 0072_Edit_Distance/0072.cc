
#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
 public:
  int minDistance(const string word1, const string word2) {
    const int length1 = word1.size(), length2 = word2.size();
    dp_.assign(length1 + 1, vector<int>(length2 + 1, -1));
    for (int i = 0; i < length1 + 1; ++i) dp_[i][length2] = length1 - i;
    for (int i = 0; i < length2 + 1; ++i) dp_[length1][i] = length2 - i;
    return minDistance(word1, word2, 0, 0);
  }

 private:
  vector<vector<int>> dp_;
  int minDistance(const string &word1, const string &word2, int index1, int index2) {
    // if (index1 == word1.size()) return word2.size() - index2;
    // if (index2 == word2.size()) return word1.size() - index1;
    if (dp_[index1][index2] != -1) return dp_[index1][index2];
    const int delete_index1 = 1 + minDistance(word1, word2, index1 + 1, index2);
    const int insert_at_index1 = 1 + minDistance(word1, word2, index1, index2 + 1);
    const int replace_or_keep_both = (word1[index1] == word2[index2] ? 0 : 1) + minDistance(word1, word2, index1 + 1, index2 + 1);
    dp_[index1][index2] = std::min(replace_or_keep_both, std::min(delete_index1, insert_at_index1));
    return dp_[index1][index2];
  }
};

int main(int argc, char *argv[]) {
  cout << "__cplusplus: " << __cplusplus << endl;
  return 0;
  string str1 = "horse", str2 = "ros";
  Solution sln;
  assert(3 == sln.minDistance(str1, str2));
  return 0;
}
