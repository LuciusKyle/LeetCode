
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    vector<vector<std::pair<string, int>>> words_vec(16);
    for (const auto& word : words) words_vec[word.size() - 1].push_back({word, 1});
    int max_chain = 1;
    for (size_t i = 1; i < 16; ++i)
      for (auto& word : words_vec[i])
        for (const auto& shorter_word : words_vec[i - 1])
          if (isPredecessor(shorter_word.first, word.first)) {
            word.second = std::max(word.second, shorter_word.second + 1);
            max_chain = std::max(max_chain, word.second);
          }

    return max_chain;
  }

 private:
  bool isPredecessor(const string& shorter, const string& longer) {
    // assert(longer.size() == shorter.size() + 1);
    bool found_diff = false;
    for (size_t i = 0; i < shorter.size(); ++i)
      if (found_diff) {
        if (shorter[i] != longer[i + 1]) return false;
      } else {
        if (shorter[i] != longer[i]) {
          --i;
          found_diff = true;
        }
      }

    return true;
  }
};
