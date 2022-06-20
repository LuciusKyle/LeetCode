
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class WordFilter {
 public:
  WordFilter(const vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      for (size_t suffix_len = 1 /*start from 0 will use more memory*/; suffix_len <= words[i].size(); ++suffix_len) {
        Node* temp_node = &root_;
        for (size_t j = words[i].size() - suffix_len; j < words[i].size(); ++j) {
          if (temp_node->child_nodes[words[i][j] - 'a'] == nullptr)
            temp_node->child_nodes[words[i][j] - 'a'] = new Node(i);
          temp_node = temp_node->child_nodes[words[i][j] - 'a'];
          temp_node->max_index = i;  // assign i, i is increamental, so i is greater than or equal to temp_node->child_nodes[words[i][j] - 'a']->max_index;
        }
        if (temp_node->child_nodes[26] == nullptr)
          temp_node->child_nodes[26] = new Node(i);
        temp_node = temp_node->child_nodes[26];
        temp_node->max_index = i;  // same reason.
        for (const char ch : words[i]) {
          if (temp_node->child_nodes[ch - 'a'] == nullptr)
            temp_node->child_nodes[ch - 'a'] = new Node(i);
          temp_node = temp_node->child_nodes[ch - 'a'];
          temp_node->max_index = i;  // same reason.
        }
      }
    }
  }

  // int f(const string& prefix, const string& suffix) const; will beat 79%.
  int f(const string prefix, const string suffix) const {
    auto temp_node = &root_;
    for (const char ch : suffix)
      if (temp_node->child_nodes[ch - 'a'] != nullptr)
        temp_node = temp_node->child_nodes[ch - 'a'];
      else
        return -1;
    if (temp_node->child_nodes[26] == nullptr) return -1;
    temp_node = temp_node->child_nodes[26];
    for (const char ch : prefix)
      if (temp_node->child_nodes[ch - 'a'] != nullptr)
        temp_node = temp_node->child_nodes[ch - 'a'];
      else
        return -1;
    return temp_node->max_index;
  }

 private:
  struct Node {
    Node() : max_index(-1), child_nodes{nullptr} {};
    Node(int _max_index) :  max_index(_max_index), child_nodes{nullptr} {}
    ~Node() {
      for (auto ptr : child_nodes) delete ptr;  // delete nullptr is OK;
    }
    // bool end_of_word;
    int max_index;
    Node* child_nodes[27];
  };
  Node root_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(void) {
  {
    WordFilter word_filter({"apple"});
    word_filter.f("a", "le");
  }
  {
    WordFilter word_filter({"cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba"});
    int rtn = word_filter.f("bccbacbcba", "a");
    cout << rtn << "\n";
    rtn = word_filter.f("ab", "abcaccbcaa");
    cout << rtn << "\n";
    rtn = word_filter.f("a", "aa");
    cout << rtn << "\n";
    rtn = word_filter.f("cabaaba", "abaaaa");
    cout << rtn << "\n";
    rtn = word_filter.f("cacc", "accbbcbab");
    cout << rtn << "\n";
    rtn = word_filter.f("ccbcab", "bac");
    cout << rtn << "\n";
    rtn = word_filter.f("bac", "cba");
    cout << rtn << "\n";
    rtn = word_filter.f("ac", "accabaccaa");
    cout << rtn << "\n";
    rtn = word_filter.f("bcbb", "aa");
    cout << rtn << "\n";
    rtn = word_filter.f("ccbca", "cbcababac");
    cout << rtn << "\n";
  }
  cout << endl;
  return 0;
}