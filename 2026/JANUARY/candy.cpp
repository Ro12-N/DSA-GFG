class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                ans[i]=max(ans[i],ans[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};
// Time Complexity: O(N) where N is the length of arr
// Space Complexity: O(N)