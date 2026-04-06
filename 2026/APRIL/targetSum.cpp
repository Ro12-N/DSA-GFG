class Solution {
  public:
  unordered_map<string,int>mp;
  int solve(int idx,vector<int>&arr,int t){
      if(idx>=arr.size()) return t==0;
      string key=to_string(idx)+"_"+to_string(t);
      if(mp.count(key)) return mp[key];
      int p=solve(idx+1,arr,t+arr[idx]);
      int q=solve(idx+1,arr,t-arr[idx]);
      return mp[key]= p+q;
  }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        return solve(0,arr,target);
    }
};
// Time Complexity: O(n*2^n)
// Space Complexity: O(n*2^n)

// Optimized Solution using Dynamic Programming
class Solution {
    public:
        int totalWays(vector<int>& arr, int target) {
            // code here
            int sum=0;
            for(int i:arr) sum+=i;
            if(sum<target || (sum-target)%2!=0) return 0;
            int s=(sum-target)/2;
            vector<int>dp(s+1,0);
            dp[0]=1;
            for(int i:arr){
                for(int j=s;j>=i;j--){
                    dp[j]+=dp[j-i];
                }
            }
            return dp[s];
        }
    };
// Time Complexity: O(n*s)
// Space Complexity: O(s)
// where n is the number of elements in the array and s is the sum of the elements in the array.