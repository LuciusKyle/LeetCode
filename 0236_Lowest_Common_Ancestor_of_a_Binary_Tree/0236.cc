
#include <set>
#include <vector>

using std::vector;
using std::set;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> first_traversal;

    return nullptr;
  }

 private:
  int preOrderTraversal(TreeNode* node, vector<TreeNode *>& ptr_vec, const TreeNode* p, const TreeNode* q, int count) {
    if (node == nullptr) return;
    if (node->left == p || node->right == q)
    ptr_vec.push_back(node);
    preOrderTraversal(node->left, ptr_vec, p, q, count);
    preOrderTraversal(node->right, ptr_vec, p, q, count);
  }

  void inOrderTraversal(TreeNode* node, set<TreeNode *>& in_order_traversal, const TreeNode* p, const TreeNode* q, bool start_record) {
    if (node == nullptr) return;
    inOrderTraversal(node->left, in_order_traversal, p, q, start_record);
    if (node == p || node == q) {
      if (start_record)
        return;
      else
        start_record = true;
    }
    in_order_traversal.insert(node);
    inOrderTraversal(node->right, in_order_traversal, p, q, start_record);
  }
};