
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
  bool isCompleteTree(TreeNode *root) {
    int max_depth = 0;
    {
      TreeNode *ptr = root->left;
      while (ptr != nullptr) {
        ++max_depth;
        ptr = ptr->left;
      }
    }
    vector<TreeNode *> curr_level(1, root), next_level;
    curr_level.reserve(1 << std::min(7, max_depth));
    next_level.reserve(1 << std::min(7, max_depth));
    for (int i = 0; i < max_depth - 1; ++i) {
      for (const TreeNode *node : curr_level) {
        if (node->left == nullptr || node->right == nullptr) return false;
        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      curr_level.swap(next_level);
      next_level.clear();
    }
    bool first_right_null = false;
    for (const TreeNode *node : curr_level) {
      if (node->left == nullptr && node->right != nullptr) return false;
      if (node->left != nullptr && node->right == nullptr) {
        if (first_right_null) return false;
        first_right_null = true;
        next_level.push_back(node->left);
        continue;
      }
      if (node->left == node->right) first_right_null = true;
      if (node->left != nullptr && node->right != nullptr) {
        if (first_right_null) return false;
        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
    }
    for (const TreeNode *node : next_level)
      if (node->left != node->right) return false;
    return true;
  }
};

int main(void) {
  TreeNode four(4), five(5), six(6);
  TreeNode two(2, &four, &five), three(3, &six, nullptr);
  TreeNode one(1, &two, &three);
  Solution sln;
  sln.isCompleteTree(&one);
  return 0;
}
