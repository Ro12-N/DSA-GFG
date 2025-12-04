class Solution {
  public:
  int n;
  vector<vector<int>>dp;
  int solve(vector<int>&arr,int idx,int buy){
      if(idx>=n) return 0;
      if(dp[buy][idx]!=-1) return dp[buy][idx];
      int skip=solve(arr,idx+1,buy);
      int take;
      if(buy){
          take=-arr[idx]+solve(arr,idx+1,1-buy);
      }else{
          take=arr[idx]+solve(arr,idx+2,1-buy);
      }
      return dp[buy][idx]= max(skip,take);
  }
    int maxProfit(vector<int>& arr) {
        n=arr.size();
        dp.assign(2,vector<int>(n,-1));
        return solve(arr,0,1);
    }
};

//TC : O(N*2)
//SC : O(N*2) + O(N) for recursion stack
