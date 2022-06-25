
#include <assert.h>

#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

class Solution {
 public:
  Solution() { root_.end_of_word = true; };
  vector<string> wordBreak(const string s, const vector<string> &wordDict) {
    Node *temp_node_ptr = &root_;
    for (const char ch : s) {
      if (temp_node_ptr->child_node_ptr[ch - 'a'] == nullptr) temp_node_ptr->child_node_ptr[ch - 'a'] = new Node();
      temp_node_ptr = temp_node_ptr->child_node_ptr[ch - 'a'];
    }
    temp_node_ptr->word_index = -1;
    temp_node_ptr->end_of_word = true;
    for (int i = 0; i < wordDict.size(); ++i) {
      temp_node_ptr = &root_;
      for (const char ch : wordDict[i]) {
        if (temp_node_ptr->child_node_ptr[ch - 'a'] == nullptr) temp_node_ptr->child_node_ptr[ch - 'a'] = new Node();
        temp_node_ptr = temp_node_ptr->child_node_ptr[ch - 'a'];
      }
      temp_node_ptr->word_index = i;
      temp_node_ptr->end_of_word = true;
    }
    vector<string> result;
    wordBreak(s, 0, &root_, result, wordDict);
    return result;
  }

 private:
  struct Node;
  bool wordBreak(const string &word, const size_t start_index, const Node *temp_root_ptr, vector<string> &result, const vector<string> &wordDict) {
    const Node *temp_ptr_from_top = &root_;
    for (size_t i = start_index; i < word.size(); ++i) {
      if (temp_ptr_from_top->child_node_ptr[word[i] - 'a'] == nullptr) return false;
      temp_ptr_from_top = temp_ptr_from_top->child_node_ptr[word[i] - 'a'];
      temp_root_ptr = temp_root_ptr->child_node_ptr[word[i] - 'a'];
      if (temp_ptr_from_top->end_of_word) {
        answer_cache_.push_back(temp_ptr_from_top->word_index);
        if (wordBreak(word, i + 1, temp_root_ptr, result, wordDict)) {
          if (i == word.size() - 1) {
            string str;
            for (int i = 0; i < answer_cache_.size(); ++i)
              if (answer_cache_[i] != -1)
                str.append(wordDict[answer_cache_[i]] + " ");

            if (!str.empty()) {
              str.pop_back();
              result.push_back(str);
            }
          }
        }
        answer_cache_.pop_back();
      }
    }
    return temp_ptr_from_top->end_of_word;
  }
  struct Node {
    Node() : end_of_word(false), word_index(-1), child_node_ptr{nullptr} {};
    ~Node() {
      for (auto ptr : child_node_ptr) delete ptr;
    }
    bool end_of_word;
    int word_index;
    Node *child_node_ptr[26];
  };
  Node root_;
  vector<int> answer_cache_;
};

int main(int argc, char *argv[]) {
  // assert(2 < argc);
  const string test_str = 1 < argc ? argv[1] : "catsanddog";
  vector<string> test_vec;
  for (int i = 2; i < argc; ++i)
    test_vec.push_back(argv[i]);
  Solution sln;
  auto rtn = sln.wordBreak(test_str, test_vec);
  for (const auto str : rtn) {
    cout << str << "\n";
  }
  cout << endl;
  return 0;
}
