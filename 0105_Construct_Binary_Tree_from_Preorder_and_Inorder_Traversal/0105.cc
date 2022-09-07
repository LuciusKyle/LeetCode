
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
  TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    vector<int> inorder_index_vec(6001);
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_index_vec[inorder[i] + 3000] = i;
    }
    return buildTree(preorder, 0, inorder, 0, inorder.size() - 1, inorder_index_vec);
  }

 private:
  TreeNode *buildTree(const vector<int> &preorder, const int preorder_index, const vector<int> &inorder, const int start_idx, const int end_idx, const vector<int> &inorder_index_vec) {
    TreeNode *node = new TreeNode(preorder[preorder_index]);
    const int inorder_index = inorder_index_vec[preorder[preorder_index] + 3000];
    if (inorder_index != start_idx) {
      node->left = buildTree(preorder, preorder_index + 1, inorder, start_idx, inorder_index - 1, inorder_index_vec);
    }
    if (inorder_index != end_idx) {
      node->right = buildTree(preorder, preorder_index + 1 + inorder_index - start_idx, inorder, inorder_index + 1, end_idx, inorder_index_vec);
    }
    return node;
  }
};

int main(void) {
  return 0;
}
