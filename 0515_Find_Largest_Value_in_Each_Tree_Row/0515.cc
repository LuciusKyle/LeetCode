
#include <vector>
#include <limits.h>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> largestValues(TreeNode *root) {
    if (root == nullptr) return vector<int>();
    vector<TreeNode *> pre_row(1, root);
    vector<int> rtn;
    vector<TreeNode *> new_row;
    int max_num = root->val;
    while (!pre_row.empty()) {
      rtn.push_back(max_num);
      max_num = INT_MIN;
      for (const auto ptr : pre_row) {
        if (ptr->left) {
          new_row.push_back(ptr->left);
          if (max_num < ptr->left->val) max_num = ptr->left->val;
        }
        if (ptr->right) {
          new_row.push_back(ptr->right);
          if (max_num < ptr->right->val) max_num = ptr->right->val;
        }
      }
      pre_row.clear();
      std::swap(new_row, pre_row);
    }
    return rtn;
  }
};