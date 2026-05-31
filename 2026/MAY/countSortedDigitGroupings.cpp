class Solution {
  public:
  int dp[901][101];
  int solve(int prev,int i,string &s){
      if(i==s.size()) return 1;
      if(dp[prev][i]!=-1) return  dp[prev][i];
    
      int ans=0;
      int curr=0;
      for(int j=i;j<s.size();j++){
          curr+=s[j]-'0';
          if(curr>=prev){
              ans+=solve(curr,j+1,s);
          }
      }
      return dp[prev][i]= ans;
  }
    int validGroups(string &s) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};
// TC : O(n^3)
// SC : O(n^2)
