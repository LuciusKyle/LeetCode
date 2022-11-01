
#include <set>
#include <stack>
#include <vector>

using std::set;
using std::stack;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  Solution() : answer_(nullptr) {}
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    lowestCommonAncestor_helper(root, p, q);
    return answer_;
  }

 private:
  TreeNode* answer_;
  int lowestCommonAncestor_helper(TreeNode* node, const TreeNode* p, const TreeNode* q) {
    if (node == nullptr) return 0;
    int result = node == p || node == q ? 1 : 0;
    int left_result = lowestCommonAncestor_helper(node->left, p, q);
    int right_result = lowestCommonAncestor_helper(node->right, p, q);
    if (result + left_result + right_result == 2) answer_ = node;
    return (result + left_result + right_result) > 0 ? 1 : 0;
  }
};