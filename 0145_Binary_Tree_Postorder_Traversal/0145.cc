
#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> rtn;
    preorderTraversal(root, rtn);
    return rtn;
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> rtn;
    postorderTraversal(root, rtn);
    return rtn;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> rtn;
    inorderTraversal(root, rtn);
    return rtn;
  }

 private:
  void preorderTraversal(TreeNode *node, vector<int> &rtn) {
    if (node == nullptr) return;
    rtn.push_back(node->val);
    preorderTraversal(node->left, rtn);
    preorderTraversal(node->right, rtn);
  }
  void postorderTraversal(TreeNode *node, vector<int> &rtn) {
    if (node == nullptr) return;
    postorderTraversal(node->left, rtn);
    postorderTraversal(node->right, rtn);
    rtn.push_back(node->val);
  }
  void inorderTraversal(TreeNode *node, vector<int> &rtn) {
    if (node == nullptr) return;
    inorderTraversal(node->left, rtn);
    rtn.push_back(node->val);
    inorderTraversal(node->right, rtn);
  }
};