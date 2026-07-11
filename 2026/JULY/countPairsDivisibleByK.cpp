class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int ans=0;
        unordered_map<int,int>mp;
        for(auto i:arr){
            int curr=i%k;
            ans+=mp[(k-curr)%k];
            mp[curr]++;
        }
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)