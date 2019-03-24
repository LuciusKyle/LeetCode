
#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_0105 {
 public:
  TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    if (preorder.size() == 1) return new TreeNode(preorder[0]);
    TreeNode* root = new TreeNode(preorder.front());
    size_t left_tree_count = 0;
    for (const int val : inorder) {
      if (val == preorder.front()) break;
      ++left_tree_count;
    }
    root->left = buildTree(
        {preorder.cbegin() + 1, preorder.cbegin() + 1 + left_tree_count},
        {inorder.cbegin(), inorder.cbegin() + left_tree_count});
    root->right =
        buildTree({preorder.cbegin() + 1 + left_tree_count, preorder.cend()},
                  {inorder.cbegin() + 1 + left_tree_count, inorder.cend()});
    return root;
  }
  // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {}
};

class Solution {
 public:
  // TreeNode* buildTree(const vector<int>& preorder, const vector<int>&
  // inorder) {
  //   if (preorder.empty()) return nullptr;
  //   if (preorder.size() == 1) return new TreeNode(preorder[0]);
  //   TreeNode* root = new TreeNode(preorder.front());
  //   size_t left_tree_count = 0;
  //   for (const int val : inorder) {
  //     if (val == preorder.front()) break;
  //     ++left_tree_count;
  //   }
  //   root->left = buildTree(
  //       {preorder.cbegin() + 1, preorder.cbegin() + 1 + left_tree_count},
  //       {inorder.cbegin(), inorder.cbegin() + left_tree_count});
  //   root->right =
  //       buildTree({preorder.cbegin() + 1 + left_tree_count, preorder.cend()},
  //                 {inorder.cbegin() + 1 + left_tree_count, inorder.cend()});
  //   return root;
  // }

  // this function won't pass leetcode test. stack-overflow.
  TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
    if (postorder.empty()) return nullptr;
    if (postorder.size() == 1) return new TreeNode(postorder.front());
    TreeNode* root = new TreeNode(postorder.back());
    size_t left_tree_count = 0;
    for (const int val : inorder) {
      if (val == postorder.front()) break;
      ++left_tree_count;
    }
    root->left = buildTree(
        {preorder.cbegin() + 1, preorder.cbegin() + 1 + left_tree_count},
        {inorder.cbegin(), inorder.cbegin() + left_tree_count});
    root->right =
        buildTree({preorder.cbegin() + 1 + left_tree_count, preorder.cend()},
                  {inorder.cbegin() + 1 + left_tree_count, inorder.cend()});
    return root;
  }
};

int main(void) {
  Solution sln;
  
  return 0;
}
