
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
  bool isBalanced(TreeNode *root) { return TreeHeight(root, 0) != -1; }

 private:
  int TreeHeight(TreeNode *node, int cur_height) {
    if(cur_height == -1) return -1;
    if (node == nullptr) return cur_height;
    int left_height = TreeHeight(node->left, cur_height + 1);
    int right_height = TreeHeight(node->right, cur_height + 1);
    if (1 < abs(left_height - right_height))
      return -1;
    else
      return left_height < right_height ? right_height : left_height; // leetcode test is sensitive to "std::max()" and "std::min()", don't use them.
  }
};
