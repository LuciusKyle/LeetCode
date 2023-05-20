
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    std::stack<TreeNode *> node_stk;
    TreeNode *curr_ptr = root;
    int number_count_ = 0;
    int answer = -1;
    while (curr_ptr != nullptr || !node_stk.empty()) {
      if (curr_ptr == nullptr) {
        ++number_count_;
        if (number_count_ == k) {
          answer = node_stk.top()->val;
          break;
        }
        curr_ptr = node_stk.top()->right;
        node_stk.pop();
      } else {
        node_stk.push(curr_ptr);
        curr_ptr = curr_ptr->left;
      }
    }
    return answer;
  }
};
