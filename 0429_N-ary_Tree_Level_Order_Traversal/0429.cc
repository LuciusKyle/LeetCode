
#include <stack>
#include <vector>

using std::stack;
using std::vector;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<const Node const*> curr_level_ptr, next_level_ptr;
    vector<vector<int>> answer;
    if (root != nullptr) curr_level_ptr.push_back(root);
    while (!curr_level_ptr.empty()) {
      answer.push_back(vector<int>());
      for (const Node* ptr : curr_level_ptr) {
        answer.back().push_back(ptr->val);
        for (const Node* child_ptr : ptr->children)
          next_level_ptr.push_back(child_ptr);
      }
      curr_level_ptr.swap(next_level_ptr);
      next_level_ptr.clear();
    }
    return answer;
  }
};