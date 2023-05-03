
#include <limits.h>

#include <algorithm>
#include <vector>

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
  int maxPathSum(TreeNode *root) {
    int answer = INT_MIN;
    maxPathSum(root, answer);
    return answer;
  }

 private:
  int maxPathSum(const TreeNode *node, int &answer) {
    if (node == nullptr) return -1000000009;
    const int left_max = maxPathSum(node->left, answer), right_max = maxPathSum(node->right, answer), rtn_val = std::max({node->val, node->val + left_max, node->val + right_max});
    answer = std::max({answer, rtn_val, node->val + left_max + right_max});
    return rtn_val;
  }
};
