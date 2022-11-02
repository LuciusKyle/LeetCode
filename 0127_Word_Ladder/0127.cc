
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
  int ladderLength(const string beginWord, const string endWord, const vector<string>& wordList) {
    vector<string> current_str_vec;
    list<string> remain_words;
    remain_words.push_back(string());
    for (const string& word : wordList)
      switch (wordDiff(beginWord, word)) {
        case 0:
          break;
        case 1:
          current_str_vec.push_back(word);
          if (word == endWord) return 2;
          break;
        default:
          remain_words.push_back(word);
          break;
      }

    int level = 1;
    vector<string> next_level;
    while (!current_str_vec.empty()) {
      ++level;
      for (const string& gene : current_str_vec) {
        auto iter = remain_words.begin();
        ++iter;
        for (; iter != remain_words.end(); ++iter)
          if (1 == wordDiff(gene, *iter)) {
            if (*iter == endWord) return level + 1;
            next_level.push_back(*iter);
            iter = remain_words.erase(iter);
            --iter;
          }
      }
      current_str_vec = next_level;
      next_level.clear();
    }
    return 0;
  }

 private:
  int wordDiff(const string& str1, const string& str2) {
    int diff = 0;
    for (int i = 0; i < str1.size(); ++i) {
      if (str1[i] != str2[i]) ++diff;
    }
    return diff;
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
