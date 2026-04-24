class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<=arr[i]){
                maxi=arr[i];
                ans++;
            }
        }
        return ans;
        
    }
};
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1) as we are using only a constant amount of extra space