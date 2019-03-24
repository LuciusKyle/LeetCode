
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int rtn = INT_MAX;
    minDepth(root, 1, rtn);
    return rtn;
  }

 private:
  void minDepth(TreeNode *node, const int cur_depth, int &min_depth) {
    if (node->left == node->right && cur_depth < min_depth) {
      min_depth = cur_depth;
      return;
    }
    if (node->left != nullptr) minDepth(node->left, cur_depth + 1, min_depth);
    if (node->right != nullptr) minDepth(node->right, cur_depth + 1, min_depth);
  }
};