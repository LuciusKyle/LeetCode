
#include <algorithm>
#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return vector<vector<int>>();
    vector<vector<int>> rtn;
    rtn.push_back(vector<int>(1, root->val));
    vector<TreeNode *> cur_level(1, root);
    vector<TreeNode *> next_level;
    do {
      next_level.clear();
      for (size_t i = 0; i < cur_level.size(); ++i) {
        if (cur_level[i]->left != nullptr)
          next_level.push_back(cur_level[i]->left);
        if (cur_level[i]->right != nullptr)
          next_level.push_back(cur_level[i]->right);
      }
      if (!next_level.empty()) {
        rtn.push_back(vector<int>());
        for (const auto ptr : next_level) rtn.back().push_back(ptr->val);
        cur_level = next_level;
      }
    } while (!next_level.empty());
    return rtn;
  }

  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == nullptr) return vector<vector<int>>();
    vector<vector<int>> rtn;
    rtn.push_back(vector<int>(1, root->val));
    vector<TreeNode *> cur_level(1, root);
    vector<TreeNode *> next_level;
    do {
      next_level.clear();
      for (size_t i = 0; i < cur_level.size(); ++i) {
        if (cur_level[i]->left != nullptr)
          next_level.push_back(cur_level[i]->left);
        if (cur_level[i]->right != nullptr)
          next_level.push_back(cur_level[i]->right);
      }
      if (!next_level.empty()) {
        rtn.push_back(vector<int>());
        for (const auto ptr : next_level) rtn.back().push_back(ptr->val);
        cur_level = next_level;
      }
    } while (!next_level.empty());
    std::reverse(rtn.begin(), rtn.end());
    return rtn;
  }
};

int main(void) {
  TreeNode root(1);
  TreeNode t1(2);
  TreeNode t2(3);

  root.left = &t1;
  // root.right = &t2;

  Solution sln;
  auto rtn = sln.levelOrder(&root);

  return 0;
}
