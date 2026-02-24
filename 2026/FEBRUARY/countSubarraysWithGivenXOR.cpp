class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long ans=0;
        unordered_map<int,int>mp;
        int xr=0;
        mp[0]=1;
        for(auto i:arr){
              xr^=i;
              ans+=mp[xr^k];
              mp[xr]++;
        }
        return ans;
    }
};
// Time Complexity: O(n) due to the single pass through the array and the hash map operations
// Space Complexity: O(n) due to the hash map used to store the frequency of prefix