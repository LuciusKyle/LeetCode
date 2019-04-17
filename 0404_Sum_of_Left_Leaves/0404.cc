

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int sumOfLeftLeaves(TreeNode *root) {
    int result = 0;
    traversal(root, false, result);
    return result;
  }

 private:
  void traversal(TreeNode *node, bool left_leaf, int &result) {
    if (node == nullptr) return;
    if (left_leaf && node->left == nullptr && node->right == nullptr) {
      result += node->val;
      return;
    }
    traversal(node->left, true, result);
    traversal(node->right, false, result);
  }
};
