
#include <limits.h>

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
  Solution() : val_shift_(0) {}
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int min_val = INT_MAX, max_val = INT_MIN;
    for (const int val : inorder) {
      min_val = std::min(val, min_val);
      max_val = std::max(val, max_val);
    }
    inorder_dict_.resize(max_val - min_val + 1, -1);
    for (int i = 0; i < inorder.size(); ++i) inorder_dict_[inorder[i] - min_val] = i;
    val_shift_ = min_val;
    return buildTree(0, inorder.size(), postorder.data());
  }

 private:
  int val_shift_ /*, *inorder_vec_, *postorder_vec_*/;
  vector<int> inorder_dict_;
  TreeNode *buildTree(const int in_start, const int length, const int *postorder) const {
    if (length == 0) return nullptr;
    return new TreeNode(postorder[length - 1], buildTree(in_start, inorder_dict_[postorder[length - 1] - val_shift_] - in_start, postorder), buildTree(inorder_dict_[postorder[length - 1] - val_shift_] + 1, length - (inorder_dict_[postorder[length - 1] - val_shift_] - in_start) - 1, postorder + inorder_dict_[postorder[length - 1] - val_shift_] - in_start));
  }
};

void freeTree(TreeNode *node) {
  if (node == nullptr) return;
  freeTree(node->left);
  freeTree(node->right);
  delete node;
}

int main(void) {
  Solution sln;
  // TreeNode *temp_root = sln.buildTree({15, 20, 7}, {15, 7, 20});
  // TreeNode *root = sln.buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3});
  // freeTree(root);
  // freeTree(temp_root);
  return 0;
}
