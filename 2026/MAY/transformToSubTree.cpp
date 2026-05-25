/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  int  solve(Node* & root){
      if(!root) return 0;
      int l=solve(root->left);
      int r=solve(root->right);
      int temp=root->data;
      root->data=l+r;
      return temp+root->data;
  }
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};

// TC : o(n)
// SC : o(h) where h is the height of the tree.