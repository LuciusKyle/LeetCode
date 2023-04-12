
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
    path_prefix_sum_.push_back(0);
    count_ = 0;
    if (root != nullptr) pathSum_func(root, targetSum);
    return count_;
  }

 private:
  vector<long long> path_prefix_sum_;
  long long count_;
  void pathSum_func(const TreeNode *node, const int targetSum) {
    const long long curr_sum = node->val + path_prefix_sum_.back();
    for (int i = 0; i < path_prefix_sum_.size(); ++i) {
      if (curr_sum - path_prefix_sum_[i] == targetSum) ++count_;
    }
    path_prefix_sum_.push_back(curr_sum);
    if (node->left != nullptr)
      pathSum_func(node->left, targetSum);
    if (node->right != nullptr)
      pathSum_func(node->right, targetSum);
    path_prefix_sum_.pop_back();
  }
};
