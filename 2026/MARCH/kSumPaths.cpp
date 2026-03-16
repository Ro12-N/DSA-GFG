/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  unordered_map<long long,int>mp;
  int  cnt=0;
  void solve(Node* root ,int t,long long sum){
      if(!root) return;
      sum+=root->data;
      cnt+=mp[sum-t];
      mp[sum]++;
      solve(root->left,t,sum);
      solve(root->right,t,sum);
      mp[sum]--;
  }
    int countAllPaths(Node *root, int k) {
        // code here
        mp[0]=1;
        solve(root,k,0);
        return cnt;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once.
// Space Complexity: O(N) in the worst case due to the recursion stack and the unordered_map storing prefix sums.