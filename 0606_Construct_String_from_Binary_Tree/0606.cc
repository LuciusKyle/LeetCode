
#include <stack>
#include <string>

using std::string;

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
  string tree2str(TreeNode *root) {
    string str;
    str.reserve(96);
    tree2str(root, str);
    return str;
  }

 private:
  void tree2str(TreeNode *node, string &str) {
    str.append(std::to_string(node->val));
    if (node->left == nullptr && node->right == nullptr) return;
    str.append("(");
    if (node->left != nullptr) tree2str(node->left, str);
    str.append(")");
    if (node->right != nullptr) {
      str.append("(");
      tree2str(node->right, str);
      str.append(")");
    }
  }
};