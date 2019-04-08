

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
    invertNode(root);
    return root;
  }

 private:
  void invertNode(TreeNode *node) {
    if (node == nullptr) return;
    invertNode(node->left);
    invertNode(node->right);
    TreeNode *temp_ptr = node->left;
    node->left = node->right;
    node->right = temp_ptr;
  }
};
