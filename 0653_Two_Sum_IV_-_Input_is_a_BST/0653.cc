
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
  bool findTarget(TreeNode *root, int k) {
    vector<int> all_vals;
    TreeNode *curr_node = root;
    stack<TreeNode *> node_stk;
    while (!node_stk.empty() || curr_node != nullptr)
      if (curr_node != nullptr) {
        node_stk.push(curr_node);
        curr_node = curr_node->left;
      } else {
        all_vals.push_back(node_stk.top()->val);
        curr_node = node_stk.top()->right;
        node_stk.pop();
      }

    int l_index = 0, r_index = all_vals.size() - 1;
    while (l_index != r_index)
      if (all_vals[l_index] + all_vals[r_index] < k)
        ++l_index;
      else if (k < all_vals[l_index] + all_vals[r_index])
        --r_index;
      else
        return true;

    return false;
  }
};

int main(void) {
  TreeNode two(2);
  TreeNode four(4);
  TreeNode seven(7);
  TreeNode three(3, &two, &four);
  TreeNode six(6, nullptr, &seven);
  TreeNode five(5, &three, &six);
  Solution sln;
  sln.findTarget(&five, 9);
  return 0;
}