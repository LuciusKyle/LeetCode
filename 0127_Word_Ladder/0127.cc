
#include <limits.h>

#include <list>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using std::list;
using std::set;
using std::string;
using std::unordered_set;
using std::vector;

// 200+ ms. 48% beat.
class Solution_passed {
 public:
  int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
    if (wordList.size() == 1) return wordList[0] == endWord ? 2 : 0;

    vector<size_t> steps_count(wordList.size(), 0);
    vector<string> buffer;
    for (size_t i = 0; i < wordList.size(); ++i)
      if (ValidTransformation(beginWord, wordList[i])) {
        if (wordList[i] == endWord) return 2;
        steps_count[i] = 1;
        buffer.push_back(wordList[i]);
      }

    vector<string> buffer2;
    for (size_t i = 2; i <= wordList.size(); ++i) {
      for (const auto& word : buffer) {
        for (size_t ii = 0; ii < wordList.size(); ++ii) {
          if (steps_count[ii] == 0 && ValidTransformation(word, wordList[ii])) {
            steps_count[ii] = i;
            if (wordList[ii] == endWord) {
              return static_cast<int>(i + 1);
            }
            buffer2.push_back(wordList[ii]);
          }
        }
      }
      std::swap(buffer, buffer2);
      buffer2.clear();
    }
    return 0;
  }

 private:
  bool ValidTransformation(const string& beginWord, const string& endWord) {
    bool only_one_difference = false;
    for (size_t i = 0; i < beginWord.size(); ++i)
      if (beginWord[i] != endWord[i])
        if (only_one_difference)
          return false;
        else
          only_one_difference = true;
    return only_one_difference;
  }
};

// 900+ ms. 14% beat.
class Solution02 {
 public:
  int ladderLength(const string beginWord, const string endWord, const vector<string>& wordList) {
    unordered_set<string> cur_set(wordList.cbegin(), wordList.cend());
    if (0 == cur_set.count(endWord)) return 0;
    unordered_set<string> pre_set({beginWord});
    pre_set.reserve(wordList.size() + 10);
    int rtn = 1;
    while (!pre_set.empty()) {
      ++rtn;
      unordered_set<string> temp_set;
      temp_set.reserve(cur_set.size());
      for (auto iter = pre_set.cbegin(); iter != pre_set.cend(); ++iter) {
        for (auto iter_2 = cur_set.cbegin(); iter_2 != cur_set.cend();) {
          if (1 == wordDifferential(*iter, *iter_2)) {
            if (*iter_2 == endWord) return rtn;
            temp_set.insert(*iter_2);
            iter_2 = cur_set.erase(iter_2);
          } else
            ++iter_2;
        }
      }
      temp_set.swap(pre_set);
    }
    return 0;
  }

 private:
  int wordDifferential(const string& x, const string& y) {
    int rtn = 0;
    for (decltype(y.size()) i = 0; i < y.size(); ++i)
      if (x[i] != y[i]) ++rtn;
    return rtn;
  }
};

// 1500 ms. WTF?
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
    vector<bool> touched(wordList.size(), false);
    vector<string> pre_vec({beginWord});
    pre_vec.reserve(wordList.size());
    vector<string> cur_vec;
    cur_vec.reserve(wordList.size());
    int rtn = 1;
    while (!pre_vec.empty()) {
      ++rtn;
      for (const auto& word : pre_vec)
        for (size_t i = 0; i < wordList.size(); ++i)
          if (!touched[i]) {
            int diff_count = 0;
            for (int ii = 0; ii < word.size(); ++ii)
              if (word[ii] != wordList[i][ii]) ++diff_count;
            if (diff_count == 1) {
              if (wordList[i] == endWord)
                return rtn;
              else {
                cur_vec.push_back(wordList[i]);
                touched[i] = true;
              }
            }
          }
      cur_vec.swap(pre_vec);
      cur_vec.clear();
    }
    return 0;
  }
};

int main(const int argc, const char* argv[]) {
  Solution_passed sln;
  Solution sln2;
  int rtn = sln.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
  rtn = sln.ladderLength("qa", "sq", {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"});
  int rtn2 = sln2.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
  rtn2 = sln2.ladderLength("qa", "sq", {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"});
  return 0;
}
