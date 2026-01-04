class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i=0;
        int sum=0;
        int maxi=0;
        for(int j=0;j<arr.size();j++){
            sum+=arr[j];
            if(j-i+1>k){
                sum-=arr[i++];
            }
            if(j-i+1==k) maxi=max(maxi,sum);
            
        }
        return maxi;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)