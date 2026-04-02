class Solution {
  public:
  int dp[2][50];
  int solve(int prev,int n){
      if(n==0) return 1;
      if(n==1){
          if(prev==1) return 1;
          return 2;
      }
      if(dp[prev][n]!=-1) return dp[prev][n];
      
      if(prev==1)
        return dp[prev][n]= solve(0,n-1);
        if(prev==0)
        return dp[prev][n]= solve(1,n-1)+solve(0,n-1);
  }
    int countStrings(int n) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)