
#include <memory>
#include <string>
#include <vector>

using std::string;

class Trie {
 public:
  Trie() : root_(std::make_shared<Node>()) {}

  void insert(const string word) {
    std::shared_ptr<Node> temp_node_ptr = root_;
    for (const char ch : word) {
      if (temp_node_ptr->child_nodes[ch - 'a'] == nullptr)
        temp_node_ptr->child_nodes[ch - 'a'] = std::make_shared<Node>();

      temp_node_ptr = temp_node_ptr->child_nodes[ch - 'a'];
    }
    temp_node_ptr->end_of_word = true;
  }

  bool search(const string word) {
    std::shared_ptr<Node> temp_node_ptr = root_;
    for (const char ch : word) {
      if (temp_node_ptr->child_nodes[ch - 'a'] == nullptr) return false;
      temp_node_ptr = temp_node_ptr->child_nodes[ch - 'a'];
    }
    return temp_node_ptr->end_of_word;
  }

  bool startsWith(const string prefix) {
    std::shared_ptr<Node> temp_node_ptr = root_;
    for (const char ch : prefix) {
      if (temp_node_ptr->child_nodes[ch - 'a'] == nullptr) return false;
      temp_node_ptr = temp_node_ptr->child_nodes[ch - 'a'];
    }
    return true;
  }

 private:
  struct Node {
    Node() : end_of_word(false), child_nodes{nullptr} {};
    bool end_of_word;
    std::shared_ptr<Node> child_nodes[26];
  };
  std::shared_ptr<Node> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(void) {
  Trie trie;

  return 0;
}