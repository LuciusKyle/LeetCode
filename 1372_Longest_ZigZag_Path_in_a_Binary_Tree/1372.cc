
#include <stack>
#include <vector>

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
  Solution() : max_val_(0) {}
  int longestZigZag(TreeNode *root) {
    longestZigZag(root, true, 0);
    return max_val_;
    std::stack<TreeNode *> node_stk;
    std::stack<std::pair<int, int>> direction_stk;  // first: 1: left, -1: right, second: length;
    direction_stk.emplace(1, -1);
    TreeNode *ptr = root;
    int max_val = 0;
    while (!node_stk.empty() || ptr != nullptr) {
      if (ptr != nullptr) {
        const int pre_direction = direction_stk.top().first;
        node_stk.push(ptr);
        if (pre_direction != 1) {
          direction_stk.emplace(-1, direction_stk.top().second + 1);
          ptr = ptr->left;
        } else {
          direction_stk.emplace(1, direction_stk.top().second + 1);
          ptr = ptr->right;
        }
      } else {
        max_val = std::max(max_val, direction_stk.top().second);
        const int pre_direction = direction_stk.top().first;
        direction_stk.pop();
        direction_stk.top().second = 0;
        if (pre_direction == 1) {
          ptr = node_stk.top()->left;
        } else {
          ptr = node_stk.top()->right;
        }
        node_stk.pop();
      }
    }
    return max_val;
  }

 private:
  void longestZigZag(const TreeNode *node, bool from_left, int length) {
    if (node == nullptr) {
      max_val_ = std::max(length - 1, max_val_);
      return;
    }
    longestZigZag(node->right, false, from_left ? length + 1 : 1);
    longestZigZag(node->left, true, from_left ? 1 : length + 1);
  }
  int max_val_;
};
