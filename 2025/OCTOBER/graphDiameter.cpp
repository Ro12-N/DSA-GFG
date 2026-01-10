class Solution {
  public:
  int solve(vector<int>&vis,unordered_map<int,vector<int>>&mp,int curr){
    queue<pair<int,int>> q; 
    q.push({curr, 0});
    vis[curr] = true;
    int maxDist = 0;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        maxDist = max(maxDist, dist);

        for (auto j : mp[node]) {
            if (!vis[j]) {
                vis[j] = true;
                q.push({j, dist + 1});
            }
        }
    }

    return maxDist;
}
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>mp;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int ans=0;
        for(int i=0;i<V;i++){
            vector<int>vis(V,false);
            int val=solve(vis,mp,i);
            ans=max(ans,val);
        }
        return ans;
    }
};


// TC = O(V*(V+E))
// SC = O(V+E)   -> TLE