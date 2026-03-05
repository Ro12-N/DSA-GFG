class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int i=0;
        int ans=0;
        int xr=0;
        for(int j=0;j<arr.size();j++){
            xr^=arr[j];
            if(j-i+1>k){
                xr^=arr[i++];
            }
            if(j-i+1==k){
                ans=max(ans,xr);
            }
        }
        return ans;
    }
};
//Time Complexity: O(N) where N is the size of the input array.
//Space Complexity: O(1) as we are using only constant extra space.