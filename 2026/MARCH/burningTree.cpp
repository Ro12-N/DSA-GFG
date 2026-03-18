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
  unordered_map<int,vector<int>>mp;
  void solve(Node* root,int prev){
      if(!root) return;
      if(prev!=-1){
          mp[prev].push_back(root->data);
          mp[root->data].push_back(prev);
      }
      solve(root->left,root->data);
      solve(root->right,root->data);
  }
    int minTime(Node* root, int target) {
        // code here
        solve(root,-1);
        queue<int>q;
        q.push(target);
        int len=0;
        unordered_set<int>st;
        st.insert(target);
        while(!q.empty()){
            int s=q.size();
            while(s--){
            int v=q.front();
            q.pop();
            for(auto j:mp[v]){
                if(!st.count(j)){
                    st.insert(j);
                    q.push(j);
                }
            }
            }
            
            len++;
            
        }
        return len-1;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once to build the graph and then perform a breadth-first search.
// Space Complexity: O(N) in the worst case due to the recursion stack and the unordered_map storing the graph representation of the tree.