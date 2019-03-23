

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {  // problem 100.
    if ((p == nullptr) && (q == nullptr)) return true;
    if ((p == nullptr) || (q == nullptr)) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  bool isSymmetric(TreeNode* root) {  // problem 101.
    if (root == nullptr) return true;
    return isSymmetric(root->left, root->right);
  }

 private:
  bool isSymmetric(TreeNode* p, TreeNode* q) {
    if ((p == nullptr) && (q == nullptr)) return true;
    if ((p == nullptr) || (q == nullptr)) return false;
    if (p->val != q->val) return false;
    return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
  }
};

