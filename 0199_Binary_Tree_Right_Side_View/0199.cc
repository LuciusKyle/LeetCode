
#include <stack>
#include <vector>

using std::vector;
using std::stack;

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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) return vector<int>();
    vector<int> rtn;

    stack<std::pair<TreeNode *, int>> stk;
    stk.push({root, 1});
    do {
      auto node_depth_pari = stk.top();
      if (rtn.size() < node_depth_pari.second)
        rtn.push_back(node_depth_pari.first->val);
      stk.pop();
      if (node_depth_pari.first->left) stk.push({node_depth_pari.first->left, node_depth_pari.second + 1});
      if (node_depth_pari.first->right) stk.push({node_depth_pari.first->right, node_depth_pari.second + 1});
    } while (!stk.empty());
    return rtn;
  }
};