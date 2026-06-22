class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
           ans[i]=ans[i-1]+(arr[i]-arr[i/2]);
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(n) as we are using an extra array of size n to store