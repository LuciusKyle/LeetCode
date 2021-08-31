

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) invertNode(root);
    return root;
  }

 private:
  void invertNode(TreeNode* node) {
    TreeNode* temp_ptr = node->left;
    node->left = node->right;
    node->right = temp_ptr;

    if (node->left != nullptr)
      invertNode(node->left);
    if (node->right != nullptr)
      invertNode(node->right);
  }
};
