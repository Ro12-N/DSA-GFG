class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int mini=INT_MAX;
        int ans=0;
        for(auto i:prices){
            mini=min(mini,i);
            ans=max(ans,i-mini);
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)