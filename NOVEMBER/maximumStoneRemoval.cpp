class Solution {
  public:
  void dfs(vector<vector<int>>&stones,int idx,vector<int>&vis){
      vis[idx]=true;
      for(int i=0;i<vis.size();i++){
        int r=stones[i][0];
        int c=stones[i][1];
        if(!vis[i] &&(r==stones[idx][0]||c==stones[idx][1])){
            dfs(stones,i,vis);
        }
      }
}
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n=stones.size();
        vector<int>vis(n,0);
        int grp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(stones,i,vis);
                grp++;
            }
        }
        return n-grp;
    }
};