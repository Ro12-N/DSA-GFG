class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int ans=INT_MIN;
        int a=0;
        int b=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(a==0) a=1;
            if(b==0) b=1;
            a*=arr[i];
            b*=arr[n-i-1];
            ans=max(ans,max(a,b));
        }
        return ans;
        
    }
};
// Time Complexity: O(N) where N is the size of the input array
// Space Complexity: O(1)