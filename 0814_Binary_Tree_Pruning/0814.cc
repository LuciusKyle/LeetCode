
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
  TreeNode *pruneTree(TreeNode *root) { return NotContainOne(root) ? nullptr : root; }

 private:
  bool NotContainOne(TreeNode *node) {
    bool not_containing_1 = true;

    if (node->left != nullptr && !NotContainOne(node->left))
      not_containing_1 = false;
    else
      node->left = nullptr;

    if (node->right != nullptr && !NotContainOne(node->right))
      not_containing_1 = false;
    else
      node->right = nullptr;

    if (node->val == 1) not_containing_1 = false;

    return not_containing_1;
  }
};