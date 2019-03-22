
#include <assert.h>
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
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) return true;
    return isValidNode(root->left, INT_MIN, root->val) && isValidNode(root->right, root->val, INT_MAX);
  }

 private:
  bool isValidNode(TreeNode *node, const int min_val, const int max_val) {
    if (node == nullptr) return true;
    if (node->val < max_val && min_val < node->val)
      return isValidNode(node->left, min_val, node->val) && isValidNode(node->right, node->val, max_val);
    else
      return false;
  }
};

int main(void) {
  TreeNode root(2);
  TreeNode left(1);
  TreeNode right(3);
  root.left = &left;
  root.right = &right;

  Solution sln;
  assert(sln.isValidBST(&root));

  return 0;
}
