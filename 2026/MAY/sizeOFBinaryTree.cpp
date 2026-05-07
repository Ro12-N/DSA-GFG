/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int solve(Node*root){
      if(!root) return 0;
      int l=solve(root->left);
      int r=solve(root->right);
      return 1+l+r;
  }
    int getSize(Node* root) {
        // code here
        return solve(root);
    }
};
//Time Complexity: O(N) where N is the number of nodes in the binary tree.
//Space Complexity: O(H) where H is the height of the binary tree. In the