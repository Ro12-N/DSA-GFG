class Solution {
  public:
  int dp[51][305];
  int solve(vector<int>&arr,int idx,int diff,int ts,int curr){
      if(idx>=arr.size()){
          int remain=ts-curr;
          if(curr-remain==diff) return 1;
          return 0;
      }
      if(dp[idx][curr]!=-1) return dp[idx][curr];
      int take=solve(arr,idx+1,diff,ts,curr+arr[idx]);
      int skip=solve(arr,idx+1,diff,ts,curr);
      return dp[idx][curr]= take+skip;
  }

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int cnt=0;
        int ts=0;
        for(auto i:arr) ts+=i;
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,diff,ts,0);
       
    }
};
//  Time Complexity: O(n * ts), where n is the size of the array and ts is the total sum of array elements.
//  Space Complexity: O(n * ts) for the memoization table plus O(n) for recursion stack.

