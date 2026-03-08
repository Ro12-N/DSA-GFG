class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
         int dp[51][1001];
        memset(dp,0,sizeof(dp));

        int mod = 1e9+7;

        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int sum=0;sum<=x;sum++){
                for(int f=1; f<=m && f<=sum; f++){
                    dp[i][sum] = (dp[i][sum] + dp[i-1][sum-f]) % mod;
                }
            }
        }

        return dp[n][x];
    }
};
//Time Complexity: O(n*x*m) where n is the number of dice, x is the required sum and m is the number of faces on each die.
//Space Complexity: O(n*x) where n is the number of dice and x is the required sum.


// Another approach using memoization

class Solution {
  public:
  int dp[51][51];
  int solve(int n,int &k,int target){
      if(target<0) return 0;
      if(n==0) return target==0;
      if(dp[n][target]!=-1) return dp[n][target];
      int ways=0;
      for(int i=1;i<=k;i++){
          ways=ways+solve(n-1,k,target-i);
      }
      return dp[n][target]= ways;
  }
    int noOfWays(int m, int n, int x) {
        // code here
        memset(dp,-1,sizeof(dp));
       return solve(n,m,x);
    }
};

//Time Complexity: O(n*x*m) where n is the number of dice, x is the required sum and m is the number of faces on each die.
//Space Complexity: O(n*x) where n is the number of dice and x is the required sum.