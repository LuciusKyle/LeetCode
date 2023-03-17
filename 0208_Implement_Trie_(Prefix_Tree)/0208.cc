
#include <string>
#include <vector>

using std::string;
using std::vector;

class Trie {
 public:
  Trie() : root_(new Node) {}
  ~Trie() {
    freeNodes(root_);
    delete root_;
  }

  void insert(const string word) {
    Node* temp_ptr = root_;
    for (const char ch : word) {
      if (temp_ptr->nodes[ch - 'a'] == nullptr) temp_ptr->nodes[ch - 'a'] = new Node;
      temp_ptr = temp_ptr->nodes[ch - 'a'];
    }
    temp_ptr->end_of_word = true;
  }

  bool search(const string word) const {
    Node* temp_ptr = root_;
    for (const char ch : word) {
      if (temp_ptr->nodes[ch - 'a'] == nullptr) return false;
      temp_ptr = temp_ptr->nodes[ch - 'a'];
    }
    return temp_ptr->end_of_word;
  }

  bool startsWith(const string prefix) const {
    Node* temp_ptr = root_;
    for (const char ch : prefix) {
      if (temp_ptr->nodes[ch - 'a'] == nullptr) return false;
      temp_ptr = temp_ptr->nodes[ch - 'a'];
    }
    return true;
  }

 private:
  struct Node {
    Node() : end_of_word(false), nodes{nullptr} {};
    bool end_of_word;
    Node* nodes[26];
  };

  void freeNodes(Node* node) {
    for (Node* child_node : node->nodes) {
      if (child_node != nullptr) {
        freeNodes(child_node);
        delete child_node;
      }
    }
  }
  Node* root_;
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