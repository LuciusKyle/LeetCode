
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
  int widthOfBinaryTree(TreeNode *root) {
    vector<std::pair<TreeNode *, long>> curr_level, next_level;
    curr_level.emplace_back(root, 0);
    long max_width = 0;
    while (!curr_level.empty()) {
      max_width = std::max(max_width, curr_level.back().second - curr_level.front().second);
      const long left_pos = curr_level.front().second * 2;
      for (const auto p : curr_level) {
        const long pos = p.second * 2;
        if (p.first->left != nullptr)
          next_level.emplace_back(p.first->left, pos - left_pos);
        if (p.first->right != nullptr)
          next_level.emplace_back(p.first->right, pos - left_pos + 1);
      }
      curr_level.swap(next_level);
      next_level.clear();
    }
    return max_width + 1;
  }
};
