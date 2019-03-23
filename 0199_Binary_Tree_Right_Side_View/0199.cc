
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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) return vector<int>();
    vector<int> rtn;
    preorderTraversalFromRight(root, 0, rtn);
    vector<int> rtn2;
    rtn2.push_back(root->val);
    for (const int val : rtn) rtn2.push_back(val);
    return rtn2;
  }

 private:
  void preorderTraversalFromRight(TreeNode *node, const int cur_depth, vector<int> &rtn) {
    if (node == nullptr) return;
    if (int(rtn.size()) < cur_depth) rtn.push_back(node->val);
    preorderTraversalFromRight(node->right, cur_depth + 1, rtn);
    preorderTraversalFromRight(node->left, cur_depth + 1, rtn);
  }
};