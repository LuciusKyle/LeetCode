
#include <algorithm>  // for std::max

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isBalanced(TreeNode *root) {}

 private:
  int TreeHeight(TreeNode *node, int cur_height) {
    if (node == nullptr)
      return cur_height;
    else
      return std::max(TreeHeight(node->left, cur_height + 1),
                      TreeHeight(node->right, cur_height + 1));
  }

  void traversal(const TreeNode *node, const int left_height, const int right_height) {
    if(node->left!=nullptr) traversal(node->left, left_height +1, right_height+1);
  }
};
