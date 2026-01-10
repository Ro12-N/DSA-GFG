class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int i=0;
        int n=arr.size();
        int ans=INT_MIN;
        int curr=0;
        for(int j=0;j<n;j++){
            curr^=arr[j];
            if(j-i+1>k){
                curr^=arr[i++];
            }
            if(j-i+1==k){
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)