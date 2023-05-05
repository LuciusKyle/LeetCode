
#include <ctype.h>

#include <unordered_map>
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
  int pathSum(TreeNode *root, int targetSum) {
    path_prefix_sum_.insert({0, 1});
    count_ = 0;
    if (root != nullptr) pathSum_func(root, targetSum, 0);
    return count_;
  }

 private:
  std::unordered_map<long long, int> path_prefix_sum_;
  int count_;
  void pathSum_func(const TreeNode *node, const int targetSum, const long long prefix_sum) {
    const long long curr_sum = node->val + prefix_sum;
    if (path_prefix_sum_.count(curr_sum - targetSum) != 0)
      count_ += path_prefix_sum_[curr_sum - targetSum];
    ++path_prefix_sum_[curr_sum];
    if (node->left != nullptr)
      pathSum_func(node->left, targetSum, curr_sum);
    if (node->right != nullptr)
      pathSum_func(node->right, targetSum, curr_sum);
    --path_prefix_sum_[curr_sum];
  }
};
