class Solution {
  public:
  int dp[1001][1001];
  int solve(vector<int>&arr,int i,int j){
      if(i>j) return 0;
      if(i==j) return arr[i];
      if(dp[i][j]!=-1) return dp[i][j];
      int ti=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
      int tj=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
      return  dp[i][j]= max(ti,tj);
  }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};