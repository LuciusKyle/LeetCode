
#include <vector>

using std::vector;

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
  Solution() : max_depth_(-1), left_val_(0) {}
  int findBottomLeftValue(TreeNode *root) {
    findBottomLeftValue(root, 0);
    return left_val_;
  }

 private:
  void findBottomLeftValue(const TreeNode *node, const int depth) {
    if (max_depth_ < depth) {
      max_depth_ = depth;
      left_val_ = node->val;
    }
    if (node->left != nullptr) findBottomLeftValue(node->left, depth + 1);
    if (node->right != nullptr) findBottomLeftValue(node->right, depth + 1);
  }
  int max_depth_;
  int left_val_;
};
