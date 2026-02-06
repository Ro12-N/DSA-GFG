class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ans=0;
        for(auto i:left) ans=max(ans,i);
        for(auto i:right) ans=max(ans,n-i);
        return ans;
    }
};
// Time Complexity: O(L + R) where L is the size of left and R is the size of right
// Space Complexity: O(1)