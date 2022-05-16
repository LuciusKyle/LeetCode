
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
    deepestLeavesSum(root, 0);
    return answer_cache_.back();
  }

 private:
  void deepestLeavesSum(const TreeNode *node, const size_t depth) {
    if (answer_cache_.size() <= depth) answer_cache_.push_back(0);
    answer_cache_[depth] += node->val;
    if (node->left) deepestLeavesSum(node->left, depth + 1);
    if (node->right) deepestLeavesSum(node->right, depth + 1);
  }
  vector<int> answer_cache_;
};