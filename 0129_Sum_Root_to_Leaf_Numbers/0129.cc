

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  Solution() : rtn(0) {}
  int sumNumbers(const TreeNode *root) {
    TreeTraversal(root, 0);
    return rtn;
  }

 private:
  int rtn;
  void TreeTraversal(const TreeNode *node, const int val) {
    if (node->left == node->right) rtn += val * 10 + node->val;
    if (node->left != nullptr) TreeTraversal(node->left, val * 10 + node->val);
    if (node->right != nullptr) TreeTraversal(node->right, val * 10 + node->val);
  }
};

int main(void) { return 0; }