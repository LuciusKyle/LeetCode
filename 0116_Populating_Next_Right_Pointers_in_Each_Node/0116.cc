
#include <vector>;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

class Solution {
 public:
  Node* connect(Node* root) {
    preOrderTraversal(root);
    return root;
  }

 private:
  void preOrderTraversal(Node* node) {
    if (node == nullptr) return;
    if (node->left != nullptr) {
      node->left->next = node->right;
      if (node->next != nullptr) node->right->next = node->next->left;
    }
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
};