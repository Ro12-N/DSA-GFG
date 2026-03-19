/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(Node*root,int &cnt){
      if(!root) return 0;
      int l=solve(root->left,cnt);
      int r=solve(root->right,cnt);
      cnt+=abs(l)+abs(r);
      return (l+r+root->data)-1;
  }
    int distCandy(Node* root) {
        // code here
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once.
// Space Complexity: O(H) where H is the height of the tree, due to the recursion stack. In the worst case (skewed tree), H can be O(N).