
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
    vector<TreeNode*> pre_order_traversal;
    preOrderTraversal(root, pre_order_traversal, p, q);
    set<TreeNode*> in_order_traversal;
    inOrderTraversal(root, in_order_traversal, p, q, false);
    for (int i = pre_order_traversal.size() - 1; 0 <= i; --i)
      if (in_order_traversal.find(pre_order_traversal[i]) != in_order_traversal.end())
        return pre_order_traversal[i];

    return nullptr;
  }

 private:
  void preOrderTraversal(TreeNode* node, vector<TreeNode *>& pre_order_traversal, const TreeNode* p, const TreeNode* q) {
    if (node == nullptr || node == p || node == q) return;
    pre_order_traversal.push_back(node);
    preOrderTraversal(node->left, pre_order_traversal, p, q);
    preOrderTraversal(node->right, pre_order_traversal, p, q);
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