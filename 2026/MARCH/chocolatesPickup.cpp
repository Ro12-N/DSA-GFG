class Solution {
  public:
  int n,m;
int dp[71][71][71];
int solve(vector<vector<int>>&grid,int row,int c1,int c2){
    if(row>=n) return 0;
    if(dp[row][c1][c2]!=-1) return dp[row][c1][c2];
    int cherry=grid[row][c1];
    if(c1!=c2){
        cherry+=grid[row][c2];
    }
   
   int ans=0;
    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            int nr=row+1;
            int nc1=c1+a;
            int nc2=c2+b;
            if(nc1>=0 &&nc1<m &&nc2>=0&&nc2<m){
             ans=max(ans,solve(grid,nr,nc1,nc2));
            }
        }
    }
    return dp[row][c1][c2]= cherry+ans;
}
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};
// Time Complexity: O(n * m²)
// Space Complexity: O(n * m²)