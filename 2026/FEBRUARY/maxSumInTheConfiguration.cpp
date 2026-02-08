class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
       long long ans=0;
       int currsum=0;
       int n=arr.size();
       for(int i=0;i<n;i++){
           currsum+=arr[i];
           ans+=(i*arr[i]);
       }
       long long res=ans;
       for(int i=1;i<n;i++){
           ans=ans+currsum-(1LL*arr[n-i]*n);
           res=max(res,ans);
       }
       return res;
    }
};
// Time Complexity: O(N) where N is the size of the input array
// Space Complexity: O(1)