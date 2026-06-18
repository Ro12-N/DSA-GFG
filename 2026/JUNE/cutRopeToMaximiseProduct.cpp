class Solution {
  public:
  int dp[59];
  int solve(int n){
      if(n<=2) return 1;
      if(dp[n]!=-1) return dp[n];
      int c=1;
      for(int i=1;i<=n;i++){
          int curr=i*solve(n-i);
          c=max(c,curr);
      }
      return dp[n]= c;
  }
    int maxProduct(int n) {
        // code here
        if(n<=2) return 1;
        if(n==3) return 2;
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
// TC : O(n^2) due to the recursive calls and memoization
// SC : O(n) for the dp array


// OPTIMAL SOLUTION
class Solution {
public:
    int maxProduct(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int ans = 1;

        while (n > 4) {
            ans *= 3;
            n -= 3;
        }

        return ans * n;
    }
};
// Time Complexity: O(n/3) which simplifies to O(n) in the worst case
// Space Complexity: O(1) as we are using constant space