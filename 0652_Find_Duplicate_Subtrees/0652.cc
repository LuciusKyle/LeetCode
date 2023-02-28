
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> answer;
    nodeHash(root, answer);
    return answer;
  }

 private:
  map<string, int> tree_structure;
  string nodeHash(TreeNode *node, vector<TreeNode *> &answer) {
    if (node == nullptr) return "#";
    const string node_str = std::to_string(node->val) + "L" + nodeHash(node->left, answer) + "R" + nodeHash(node->right, answer);
    ++tree_structure[node_str];
    if (tree_structure[node_str] == 2) answer.push_back(node);
    return node_str;
  }
};