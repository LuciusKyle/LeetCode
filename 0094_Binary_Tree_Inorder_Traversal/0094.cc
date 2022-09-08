
#include <stack>
#include <vector>

using std::stack;
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
  // 0144: https://leetcode.com/problems/binary-tree-preorder-traversal
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result_vec;
    stack<TreeNode *> node_stk;
    TreeNode *curr = root;
    while (curr || !node_stk.empty())
      if (curr != nullptr) {
        result_vec.push_back(curr->val);
        node_stk.push(curr);
        curr = curr->left;
      } else {
        curr = node_stk.top()->right;
        node_stk.pop();
      }

    return result_vec;
  }

  // 0145: https://leetcode.com/problems/binary-tree-postorder-traversal
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result_vec;
    stack<TreeNode *> node_stk;
    TreeNode *curr = root;
    while (curr != nullptr || !node_stk.empty())
      if (curr != nullptr) {
        node_stk.push(curr);
        node_stk.push(curr);
        curr = curr->left;
      } else {
        curr = node_stk.top();
        node_stk.pop();
        if (node_stk.empty() || curr != node_stk.top()) {
          result_vec.push_back(curr->val);
          curr = nullptr;
        } else {
          curr = curr->right;
        }
      }

    return result_vec;
  }

  // 0094: https://leetcode.com/problems/binary-tree-inorder-traversal
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result_vec;
    stack<TreeNode *> node_stk;
    TreeNode *curr = root;
    while (curr || !node_stk.empty())
      if (curr != nullptr) {
        node_stk.push(curr);
        curr = curr->left;
      } else {
        result_vec.push_back(node_stk.top()->val);
        curr = node_stk.top()->right;
        node_stk.pop();
      }

    return result_vec;
  }
};