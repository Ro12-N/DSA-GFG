class Solution {
  public:
    bool check(vector<int>&arr, int k,int w, int mid){
        int n=arr.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++) vec[i]=max(0, mid-arr[i]);
        vector<int>v(n);
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum>=vec[i]) continue;
            count+=vec[i]-sum;
            if(i+w<n) v[i+w]-=vec[i]-sum;
            sum=vec[i];
        }
        return count<=k;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int l=*min_element(arr.begin(),arr.end());
        int r=l+k;
        int mid,ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(arr, k, w ,mid)) ans=mid, l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// Time Complexity: O(N log M) where N is the size of the input array and M is the maximum possible height after adding k units of height
// Space Complexity: O(N) due to the additional vectors used in the check function