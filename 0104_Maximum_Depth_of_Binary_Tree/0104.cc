
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    max_depth_ = 0;
    treeTraversal(root, 1);
    return max_depth_;
  }

 private:
  void treeTraversal(TreeNode *node, const int depth) {
    if (max_depth_ < depth) max_depth_ = depth;
    if (node->left != nullptr) treeTraversal(node->left, depth + 1);
    if (node->right != nullptr) treeTraversal(node->right, depth + 1);
  }

  int max_depth_;
};