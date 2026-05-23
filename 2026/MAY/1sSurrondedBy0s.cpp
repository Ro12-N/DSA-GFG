class Solution {
  public:
  int n,m;
  vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
  void solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
      if(i<0||j<0||i>=n||j>=m||grid[i][j]==0||vis[i][j]) return;
      vis[i][j]=1;
      for(auto d:dir){
          int ni=i+d[0];
          int nj=j+d[1];
          solve(ni,nj,grid,vis);
      }
      
  }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1 && !vis[i][j]){
                        solve(i,j,grid,vis);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]) ans++;
            }
        }
        return ans;
        
    }
};
// TC : o(n*m)
// SC : o(n*m)