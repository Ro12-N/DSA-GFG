/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  int mini,maxi;
  void solve(Node* root,unordered_map<int,int>&mp,int curr){
      if(!root) return;
      mini=min(mini,curr);
      maxi=max(maxi,curr);
      mp[curr]+=root->data;
      solve(root->left,mp,curr-1);
      solve(root->right,mp,curr+1);

  }
    vector<int> verticalSum(Node* root) {
        // code here
        mini=INT_MAX;
        maxi=INT_MIN;
        unordered_map<int,int>mp;
        solve(root,mp,0);
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            ans.push_back(mp[i]);
        }
        return ans;
        
    }
};
// TC : o(n)
// SC : o(n)