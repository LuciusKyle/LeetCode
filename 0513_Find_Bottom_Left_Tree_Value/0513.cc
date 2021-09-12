
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
  int findBottomLeftValue(TreeNode *root) {
    vector<TreeNode *> pre_row(1, root);
    vector<TreeNode *> next_row;
    if (root->left != nullptr) next_row.push_back(root->left);
    if (root->right != nullptr) next_row.push_back(root->right);
    while (!next_row.empty()) {
      pre_row.swap(next_row);
      next_row.clear();
      for (const TreeNode *ptr : pre_row) {
        if (ptr->left != nullptr) next_row.push_back(ptr->left);
        if (ptr->right != nullptr) next_row.push_back(ptr->right);
      }
    }
    return pre_row[0]->val;
  }
};
