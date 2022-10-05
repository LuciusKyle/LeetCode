
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
  TreeNode *addOneRow(TreeNode *root, const int val, const int depth) {
    TreeNode auxiliary_root(0, root, nullptr);
    addOneRow(root, &auxiliary_root, true, val, depth, 1);
    return auxiliary_root.left;
  }

 private:
  void addOneRow(TreeNode *node, TreeNode *parent_node, bool left_child, const int val, const int depth, const int curr_depth) {
    if (curr_depth == depth) {
      if (left_child)
        parent_node->left = new TreeNode(val, node, nullptr);
      else
        parent_node->right = new TreeNode(val, nullptr, node);
    }
    if (depth < curr_depth) return;
    if (node == nullptr) return;
    addOneRow(node->left, node, true, val, depth, curr_depth + 1);
    addOneRow(node->right, node, false, val, depth, curr_depth + 1);
  }
};
