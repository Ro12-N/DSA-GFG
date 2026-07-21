class Solution {
  public:
 
  int dp[10][82];
  int s;
  int solve(int n,int sum){
      if(sum<0) return 0;
      if(n==0){
         return sum==0;
      }
      if(dp[n][sum]!=-1) return dp[n][sum];
      int ans=0;
      for(int i=0;i<=9;i++){
          if(s==n && i==0) continue;
          ans +=solve(n-1,sum-i);
      }
      return dp[n][sum]= ans;
  }
    int countWays(int n, int sum) {
        // code here
        s=n;
        memset(dp,-1,sizeof(dp));
       int res=solve(n,sum);
       return (res==0)?-1:res;
    }
};
// Time Complexity: O(n*sum) where n is the number of digits and sum is the given sum
// Space Complexity: O(n*sum) for the dp array