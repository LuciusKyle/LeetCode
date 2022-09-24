
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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> path_vec;
    vector<vector<int>> answer;
    pathSum(root, targetSum, 0, path_vec, answer);
    return answer;
  }

 private:
  void pathSum(TreeNode *node, const int targetSum, const int curr_sum, vector<int> &curr_vec, vector<vector<int>> &answer) {
    if (node == nullptr) return;
    curr_vec.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr && curr_sum + node->val == targetSum) answer.push_back(curr_vec);
    pathSum(node->left, targetSum, curr_sum + node->val, curr_vec, answer);
    pathSum(node->right, targetSum, curr_sum + node->val, curr_vec, answer);
    curr_vec.pop_back();
  }
};
