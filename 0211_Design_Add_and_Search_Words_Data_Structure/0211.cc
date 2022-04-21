
#include <map>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;

class WordDictionary {
 public:
  WordDictionary() {}

  void addWord(string word) {
    if (all_words_.insert(word).second)
      all_words_vec_.push_back(word);
  }

  bool search(string target) {
    for (const string& word : all_words_vec_)
      if (same_word(word, target)) return true;

    return false;
  }

 private:
  set<string> all_words_;
  vector<string> all_words_vec_;
  bool same_word(const string& word, const string& target) {
    if (word.size() != target.size()) return false;
    for (size_t i = 0; i < word.size(); ++i) {
      if (target[i] == '.') continue;
      if (word[i] != target[i]) return false;
    }
    return true;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */