
#include <assert.h>
#include <memory.h>
#include <string.h>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<int> findSubstring(const string s, const vector<string>& words) {
    vector<int> result;
    const unsigned short word_len = words[0].size();
    const unsigned short word_num = words.size();
    unsigned short* word_count = new unsigned short[word_num * 2]{static_cast<unsigned short>(0)};
    unordered_map<string, short> words_index_map;
    words_index_map.reserve(word_num + 16);
    for (unsigned short i = 0; i < word_num; ++i) {
      const auto iter = words_index_map.find(words[i]);
      if (iter == words_index_map.end()) {
        words_index_map.insert({words[i], i});
        word_count[i] = 1;
      } else {
        ++word_count[iter->second];
      }
    }
    for (short index_shift = 0; index_shift < word_len; ++index_shift) {
      if (int(s.size()) - index_shift < word_len * word_num) continue;

      // initial sliding window.
      unsigned short* sliding_word_count = word_count + word_num;
      memset(sliding_word_count, 0, word_num * sizeof(decltype(word_count[0])));
      for (unsigned short i = 0; i < word_num; ++i) {
        const auto iter = words_index_map.find(s.substr(i * word_len + index_shift, word_len));
        if (iter != words_index_map.end())
          ++sliding_word_count[iter->second];
      }
      if (0 == memcmp(word_count, sliding_word_count, word_num * sizeof(decltype(word_count[0])))) result.push_back(0 + index_shift);

      // slide the window.
      for (int i = 1; i <= (s.size() - index_shift) / word_len - word_num; ++i) {
        auto iter = words_index_map.find(s.substr((i - 1) * word_len + index_shift, word_len));
        if (iter != words_index_map.end())
          --sliding_word_count[iter->second];
        iter = words_index_map.find(s.substr(i * word_len + word_len * (word_num - 1) + index_shift, word_len));
        if (iter != words_index_map.end())
          ++sliding_word_count[iter->second];
        if (0 == memcmp(word_count, sliding_word_count, word_num * sizeof(decltype(word_count[0])))) result.push_back(i * word_len + index_shift);
      }
    }
    delete[] word_count;
    return result;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.findSubstring("barfoothefoobarman", {"foo", "bar"});
  assert(rtn.size() == 2);
  rtn = sln.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"});
  assert(rtn.empty());
  rtn = sln.findSubstring("barfoofoobarthefoobarman", {"bar", "foo", "the"});
  assert(rtn.size() == 3);
  rtn = sln.findSubstring("a", {"bar", "foo", "the"});
  assert(rtn.empty());
  rtn = sln.findSubstring("wordgoodgoodgoodbestword", {"word","good","best","good"});
  assert(rtn.size() == 1 && rtn[0] == 8);
  rtn = sln.findSubstring("cccbcacaa", {"cc","bc"});
  assert(rtn.size() == 1 && rtn[0] == 1);
  return 0;
}