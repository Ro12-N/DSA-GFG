class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int mini=min(arr[0]+k,arr[i+1]-k);
            int maxi=max(arr[n-1]-k,arr[i]+k);
            if(mini<0) continue;
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};