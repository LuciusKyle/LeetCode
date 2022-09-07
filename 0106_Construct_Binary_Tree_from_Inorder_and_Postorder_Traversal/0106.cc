
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

class Solution_0105 {
 public:
  TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    preorder_ptr_ = &preorder;
    inorder_ptr_ = &inorder;
    int max_val = INT_MIN;
    for (const int val : inorder) {  // this for loop is time consuming.
      if (val < min_val_) min_val_ = val;
      if (max_val < val) max_val = val;
    }
    inorder_index_vec_.resize(max_val - min_val_ + 1);
    for (int i = 0; i < inorder.size(); ++i)
      inorder_index_vec_[inorder[i] - min_val_] = i;

    return buildTree(0, 0, inorder.size() - 1);
  }

 private:
  int min_val_ = INT_MAX;
  const vector<int> *preorder_ptr_ = nullptr;
  const vector<int> *inorder_ptr_ = nullptr;
  vector<int> inorder_index_vec_;

  TreeNode *buildTree(const int preorder_index, const int start_idx, const int end_idx) {
    TreeNode *node = new TreeNode((*preorder_ptr_)[preorder_index]);
    const int inorder_index = inorder_index_vec_[(*preorder_ptr_)[preorder_index] - min_val_];
    if (inorder_index != start_idx)
      node->left = buildTree(preorder_index + 1, start_idx, inorder_index - 1);
    if (inorder_index != end_idx)
      node->right = buildTree(preorder_index + 1 + inorder_index - start_idx, inorder_index + 1, end_idx);

    return node;
  }
};

class Solution {
 public:
  TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
    postorder_ptr_ = &postorder;
    inorder_ptr_ = &inorder;
    int max_val = INT_MIN;
    for (const int val : inorder) {  // this for loop is time consuming.
      if (val < min_val_) min_val_ = val;
      if (max_val < val) max_val = val;
    }
    inorder_index_vec_.resize(max_val - min_val_ + 1);
    for (int i = 0; i < inorder.size(); ++i)
      inorder_index_vec_[inorder[i] - min_val_] = i;
    return buildTree(postorder.size() - 1, 0, inorder.size() - 1);
  }

 private:
  int min_val_ = INT_MAX;
  const vector<int> *postorder_ptr_ = nullptr;
  const vector<int> *inorder_ptr_ = nullptr;
  vector<int> inorder_index_vec_;

  TreeNode *buildTree(const int postorder_idx, const int inorder_start_idx, const int inorder_end_idx) {
    TreeNode *node = new TreeNode((*postorder_ptr_)[postorder_idx]);
    const int inorder_index = inorder_index_vec_[(*postorder_ptr_)[postorder_idx] - min_val_];
    if (inorder_index != inorder_end_idx)
      node->right = buildTree(postorder_idx - 1, inorder_index + 1, inorder_end_idx);
    if (inorder_index != inorder_start_idx)
      node->left = buildTree(postorder_idx - 1 - (inorder_end_idx - inorder_index), inorder_start_idx, inorder_index - 1);

    return node;
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
  TreeNode *temp_root = sln.buildTree({15, 20, 7}, {15, 7, 20});
  TreeNode *root = sln.buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3});
  freeTree(root);
  freeTree(temp_root);
  return 0;
}
