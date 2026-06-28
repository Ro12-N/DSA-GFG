class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n=height.size();
        int s=0;
        int e=n-1;
        int ans=0;
        while(s<e){
            int curr=min(height[s],height[e])*(e-s-1);
            ans=max(ans,curr);
            if(height[s]<=height[e]) s++;
            else e--;
        }
        return ans;
        
    }
};
// TC : O(n) where n is the number of bars in the histogram.
// SC : O(1) as we are using constant space.