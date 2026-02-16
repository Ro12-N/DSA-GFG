class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        int n=a.size();
        for(int i=0;i<=n-m;i++){
            ans=min(ans,a[i+m-1]-a[i]);
        }
        return ans;
    }
};
// Time Complexity: O(n log n) due to sorting the array
// Space Complexity: O(1) as we are using only a constant amount of extra space