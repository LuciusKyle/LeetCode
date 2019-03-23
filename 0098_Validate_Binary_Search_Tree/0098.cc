
#include <assert.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }

 private:
  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if ((minNode == nullptr || minNode->val < root->val) && (maxNode == nullptr || root->val < maxNode->val))
      return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
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
