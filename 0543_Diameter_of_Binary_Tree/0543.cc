
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
  int diameterOfBinaryTree(TreeNode *root) {
    int curr_max = 0;
    diameterOfBinaryTree(root, 0, curr_max);
    return curr_max;
  }

 private:
  int diameterOfBinaryTree(TreeNode *node, const int curr_depth, int &curr_max) {
    if (node == nullptr) return curr_depth - 1;
    const int left_depth = diameterOfBinaryTree(node->left, curr_depth + 1, curr_max);
    const int right_depth = diameterOfBinaryTree(node->right, curr_depth + 1, curr_max);
    const int curr_diameter = left_depth + right_depth - 2 * curr_depth;
    curr_max = curr_max < curr_diameter ? curr_diameter : curr_max;
    return left_depth < right_depth ? right_depth : left_depth;
  }
};