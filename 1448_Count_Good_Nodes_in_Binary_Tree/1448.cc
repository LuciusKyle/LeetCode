
#include <limits.h>

#include <stack>

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
  int goodNodes(TreeNode *root) {
    return goodNodes(root, INT_MIN);
  }

 private:
  int goodNodes(TreeNode *node, int curr_max) {
    if (node == nullptr) return 0;
    int ret_val = 0;
    if (curr_max <= node->val) {
      curr_max = node->val;
      ret_val = 1;
    }
    return ret_val + goodNodes(node->left, curr_max) + goodNodes(node->right, curr_max);
  }
};

void freeAllNodes(TreeNode *temp_ptr) {
  if (temp_ptr == nullptr) return;
  freeAllNodes(temp_ptr->left);
  freeAllNodes(temp_ptr->right);
  delete temp_ptr;
}

int main(void) {
  // TreeNode Six(6);
  // TreeNode Three(3, &Six, nullptr);
  // TreeNode Nine(9, nullptr, &Three);
  TreeNode Four(4);
  TreeNode Three(3, &Four, nullptr);
  TreeNode Five(5);
  TreeNode Two(2, &Three, &Five);
  TreeNode One(1, nullptr, &Two);

  Solution sln;
  int rtn = sln.goodNodes(&One);

  TreeNode *root = new TreeNode(-1);
  root->left = new TreeNode(5, new TreeNode(-2, new TreeNode(-2, new TreeNode(0), nullptr), nullptr), new TreeNode(4, nullptr, new TreeNode(-4, new TreeNode(-1), nullptr)));
  root->right = new TreeNode(2, new TreeNode(4, new TreeNode(-2, new TreeNode(-3), nullptr), new TreeNode(3)), new TreeNode(2));

  rtn = sln.goodNodes(root);
  freeAllNodes(root);
  return 0;
}
