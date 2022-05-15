
#include <vector>

using std::vector;

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
  int deepestLeavesSum(TreeNode *root) {
    vector<TreeNode *> cur_level(1, root), pre_level;
    do {
      pre_level.clear();
      for (const TreeNode *ptr : cur_level) {
        if (ptr->left != nullptr) pre_level.push_back(ptr->left);
        if (ptr->right != nullptr) pre_level.push_back(ptr->right);
      }
      std::swap(cur_level, pre_level);
    } while (!cur_level.empty());
    int sum = 0;
    for (const TreeNode *ptr : pre_level)
      sum += ptr->val;
    return sum;
  }
};