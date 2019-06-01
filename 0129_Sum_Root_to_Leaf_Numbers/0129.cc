

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int sumNumbers(const TreeNode *root) {
    rtn = 0;
    TreeTraversal(root, 0);
    return rtn;
  }

 private:
  int rtn;
  void TreeTraversal(const TreeNode *node, const int val) {
    if (node == nullptr) return;
    if (node->left == node->right) {
      rtn += val * 10 + node->val;
      return;
    }
    TreeTraversal(node->left, val * 10 + node->val);
    TreeTraversal(node->right, val * 10 + node->val);
  }
};

int main(void) { return 0; }