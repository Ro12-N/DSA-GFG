class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i-1][1]>arr[i][0]) return false;
        }
        return true;
    }
};
// Time Complexity: O(n log n) due to sorting the array
// Space Complexity: O(1) as we are using only a constant amount of extra space