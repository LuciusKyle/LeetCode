

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int countNodes(TreeNode *root) {
    int rtn = 0;
    traversal(root, rtn);
    return rtn;
  }

 private:
  void traversal(TreeNode *node, int &node_count) {
    if (node != nullptr) {
      ++node_count;
      traversal(node->left, node_count);
      traversal(node->right, node_count);
    }
  }
};

int main(void) {
  Solution sln;
  return 0;
}
