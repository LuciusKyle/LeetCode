
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
  bool hasPathSum(TreeNode *root, int targetSum) {
    return hasPathSum(root, 0, targetSum);
  }

 private:
  bool hasPathSum(TreeNode *node, const int curr_sum, const int targetSum) {
    if (node == nullptr) return false;
    if (node->left == nullptr && node->right == nullptr) {
      return (curr_sum + node->val) == targetSum;
    }
    return hasPathSum(node->left, curr_sum + node->val, targetSum) || hasPathSum(node->right, curr_sum + node->val, targetSum);
  }
};
