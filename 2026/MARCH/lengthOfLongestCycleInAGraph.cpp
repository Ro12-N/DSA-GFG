class Solution {
  public:
  int ans=-1;
  void solve(unordered_map<int,int>&mp,int u,vector<int>&vis,vector<int>&inrec,vector<int>&cnt){
      
        vis[u]=true;
        inrec[u]=true;
        if(mp.count(u)){
        int v=mp[u];
         if(!vis[v]){
             cnt[v]=cnt[u]+1;
             solve(mp,v,vis,inrec,cnt);
         }else if(inrec[v]){
             ans=max(ans,cnt[u]-cnt[v]+1);
         }
        }
        inrec[u]=false;
  }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,int>mp;
        for(auto i:edges){
            mp[i[0]]=i[1];
        }
        vector<int>vis(V,0);
        vector<int>inrec(V,0);
        vector<int>cnt(V,1);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(mp,i,vis,inrec,cnt);
            }
        }
        return ans;
    }
};

// Time Complexity: O(V) where V is the number of vertices in the graph.
// Space Complexity: O(V) for the visited, inrec, and cnt arrays.