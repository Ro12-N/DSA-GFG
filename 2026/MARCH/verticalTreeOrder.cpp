/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        while(!q.empty()){
            auto [t,v]=q.front();
            q.pop();
            mp[v].push_back(t->data);
            if(t->left){
                q.push({t->left,v-1});
            }
            if(t->right){
                q.push({t->right,v+1});
            }
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
// Time Complexity: O(N log N) due to the map insertion and traversal.
// Space Complexity: O(N) for the queue and map storage